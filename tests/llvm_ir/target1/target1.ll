define i32 @main() {
entry:
  %add = add i32 10, 20
  %sub = sub i32 %add, 5
  ret i32 %sub
}

