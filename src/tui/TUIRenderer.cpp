#include "TUIRenderer.h"

using namespace irsentry;
using namespace ftxui;

TUIRenderer::TUIRenderer()
    : m_tabIndex(1), m_leftFocus(0), m_rightFocus(0), m_colFocus(0),
      m_tabTitles{"Tables", "Logs", "Exit"}, m_logs{},
      m_screen(ScreenInteractive::Fullscreen()) {
  initializeComponents();
}

void TUIRenderer::initializeComponents() {
  initializeSections();
  initializeColumns();
  initializeTabs();
  initializePage();
  initializeMainRenderer();
}

void TUIRenderer::initializeSections() {
  m_processTiming = makeSectionComponent("process timing",
                                         [&] { return m_processTimingLines; });
  m_cycleProgress = makeSectionComponent("input scanning progress",
                                         [&] { return m_processTimingLines; });
  m_stageProgress = makeSectionComponent("hotspot scanning progress",
                                         [&] { return m_processTimingLines; });
  m_fuzzingStrategy = makeSectionComponent(
      "overall paths", [&] { return m_processTimingLines; });
  m_overallResults = makeSectionComponent("vulnerability results",
                                          [&] { return m_processTimingLines; });
  m_findings = makeSectionComponent("workers status",
                                    [&] { return m_processTimingLines; });
  m_pathGeometry = makeSectionComponent("irsentry status",
                                        [&] { return m_processTimingLines; });
}

void TUIRenderer::initializeColumns() {
  m_leftColumn = Container::Vertical(
      {m_processTiming, m_cycleProgress, m_stageProgress, m_fuzzingStrategy},
      &m_leftFocus);
  m_rightColumn = Container::Vertical(
      {m_overallResults, m_findings, m_pathGeometry}, &m_rightFocus);
  auto columns =
      Container::Horizontal({m_leftColumn, m_rightColumn}, &m_colFocus);
  m_twoColumnsRenderer = Renderer(columns, [&] {
    auto l = m_leftColumn->Render() | xflex;
    auto r = m_rightColumn->Render() | xflex;
    return hbox({l, r}) | flex;
  });
}

void TUIRenderer::initializeTabs() {

  m_logComponent = Renderer([&] {
    Elements content;
    for (auto &l : m_logs) {
      content.push_back(text(l));
    }

    return vbox(content) | focusPositionRelative(0, 1) | yframe | border;
  });

  m_logRenderer = Renderer([&] { return vbox(m_logComponent) | flex; });

  m_exitRenderer = Renderer([&] {
    return vbox({text("Exit application") | center | bold, separator(),
                 text("Press <Enter> to quit") | center,
                 text("or press q/ESC") | center}) |
           border | flex;
  });

  m_tabsContainer = Container::Tab(
      {m_twoColumnsRenderer, m_logComponent, m_exitRenderer}, &m_tabIndex);
}

void TUIRenderer::initializePage() {
  m_pageRenderer = Renderer(m_tabsContainer, [&] {
    Elements hdr;
    for (int i = 0; i < (int)m_tabTitles.size(); ++i) {
      auto label = text(" " + m_tabTitles[i] + " ");
      if (m_tabIndex == i)
        label = label | inverted | bold;
      hdr.push_back(label);
    }
    return vbox({hbox(std::move(hdr)) | center | border, separator(),
                 m_tabsContainer->Render() | flex});
  });
}

void TUIRenderer::initializeMainRenderer() {
  m_mainRenderer =
      CatchEvent(m_pageRenderer, [&](const Event &ev) { return onEvent(ev); });
}

ftxui::Component TUIRenderer::makeSectionComponent(
    std::string title, std::function<std::vector<std::string>()> get_lines) {
  return Renderer([=] { return makeSection(title, get_lines()); });
}

void TUIRenderer::run() { m_screen.Loop(m_mainRenderer); }

void irsentry::TUIRenderer::pushLog(const std::string &message) {
  m_logs.push_back(message);
  forceRefresh();
}

bool TUIRenderer::onEvent(const Event &event) {
  if (event == Event::Tab || event == Event::Character('`')) {
    m_tabIndex = (m_tabIndex + 1) % m_tabTitles.size();
    return true;
  }
  if (event == Event::Character('1')) {
    m_tabIndex = 0;
    return true;
  }
  if (event == Event::Character('2')) {
    m_tabIndex = 1;
    return true;
  }
  if (event == Event::Character('3')) {
    m_tabIndex = 2;
    return true;
  }

  if ((m_tabIndex == 2 && event == Event::Return) ||
      event == Event::Character('q') || event == Event::Escape) {
    m_screen.Exit();
    return true;
  }
  return false;
}

void irsentry::TUIRenderer::forceRefresh() { m_screen.Post(Event::Custom); }

ftxui::Element TUIRenderer::makeSection(const std::string &title,
                                        const std::vector<std::string> &lines) {
  auto header = text(" " + title + " ") | center | bold;
  Elements content;
  for (auto &l : lines)
    content.push_back(text(l));
  return vbox({header, separator(), vbox(content) | flex}) | border | flex;
}
