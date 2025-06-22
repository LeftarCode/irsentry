#pragma once

#include <deque>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
#include <vector>

namespace irsentry {

class TUIRenderer {
public:
  TUIRenderer();
  void run();
  void pushLog(const std::string &message);

private:
  int m_tabIndex;
  int m_leftFocus;
  int m_rightFocus;
  int m_colFocus;

  std::vector<std::string> m_tabTitles;
  std::vector<std::string> m_logs;

  std::vector<std::string> m_processTimingLines;
  std::vector<std::string> m_cycleProgressLines;
  std::vector<std::string> m_fuzzingStrategyLines;
  std::vector<std::string> m_stageProgressLines;
  std::vector<std::string> m_overallResultsLines;
  std::vector<std::string> m_findingsLines;
  std::vector<std::string> m_pathGeometryLines;

  ftxui::ScreenInteractive m_screen;
  ftxui::Component m_processTiming;
  ftxui::Component m_cycleProgress;
  ftxui::Component m_stageProgress;
  ftxui::Component m_fuzzingStrategy;
  ftxui::Component m_overallResults;
  ftxui::Component m_findings;
  ftxui::Component m_pathGeometry;
  ftxui::Component m_leftColumn;
  ftxui::Component m_rightColumn;
  ftxui::Component m_twoColumnsRenderer;

  ftxui::Component m_logRenderer;
  ftxui::Component m_logComponent;

  ftxui::Component m_exitRenderer;
  ftxui::Component m_tabsContainer;
  ftxui::Component m_pageRenderer;
  ftxui::Component m_mainRenderer;

  static ftxui::Element makeSection(const std::string &title,
                                    const std::vector<std::string> &lines);

  void initializeComponents();
  void initializeSections();
  void initializeColumns();
  void initializeTabs();
  void initializePage();
  void initializeMainRenderer();
  ftxui::Component
  makeSectionComponent(std::string title,
                       std::function<std::vector<std::string>()> get_lines);

  bool onEvent(const ftxui::Event &event);
  void forceRefresh();
};

} // namespace irsentry
