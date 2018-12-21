; ModuleID = 'seashell-compiler-output'
source_filename = "seashell-compiler-output"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [12 x i8] c"height >= 0\00", align 1
@.str.1 = private unnamed_addr constant [51 x i8] c"/u1/dtompkins/.seashell/projects/_A5/q4/patterns.c\00", align 1
@__PRETTY_FUNCTION__.star_rectangle = private unnamed_addr constant [30 x i8] c"void star_rectangle(int, int)\00", align 1
@.str.2 = private unnamed_addr constant [11 x i8] c"width >= 0\00", align 1
@__PRETTY_FUNCTION__.star_row = private unnamed_addr constant [19 x i8] c"void star_row(int)\00", align 1
@.str.4 = private unnamed_addr constant [2 x i8] c"*\00", align 1
@.str.5 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@__PRETTY_FUNCTION__.star_triangle = private unnamed_addr constant [24 x i8] c"void star_triangle(int)\00", align 1
@.str.3 = private unnamed_addr constant [6 x i8] c"k > 0\00", align 1
@__PRETTY_FUNCTION__.star_diamond = private unnamed_addr constant [23 x i8] c"void star_diamond(int)\00", align 1
@.str.6 = private unnamed_addr constant [2 x i8] c" \00", align 1
@__PRETTY_FUNCTION__.digit_rectangle = private unnamed_addr constant [31 x i8] c"void digit_rectangle(int, int)\00", align 1
@.str.7 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@__PRETTY_FUNCTION__.digit_triangle = private unnamed_addr constant [25 x i8] c"void digit_triangle(int)\00", align 1

; Function Attrs: nounwind
define void @star_rectangle(i32 %height, i32 %width) #0 {
  %height.addr = alloca i32, align 4
  %width.addr = alloca i32, align 4
  %h = alloca i32, align 4
  store i32 %height, i32* %height.addr, align 4
  store i32 %width, i32* %width.addr, align 4
  %1 = load i32, i32* %height.addr, align 4
  %cmp = icmp sge i32 %1, 0
  br i1 %cmp, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([51 x i8], [51 x i8]* @.str.1, i32 0, i32 0), i32 33, i8* getelementptr inbounds ([30 x i8], [30 x i8]* @__PRETTY_FUNCTION__.star_rectangle, i32 0, i32 0)) #3
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load i32, i32* %width.addr, align 4
  %cmp1 = icmp sge i32 %6, 0
  br i1 %cmp1, label %7, label %8

; <label>:7:                                      ; preds = %5
  br label %10

; <label>:8:                                      ; preds = %5
  call void @__assert_fail(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([51 x i8], [51 x i8]* @.str.1, i32 0, i32 0), i32 34, i8* getelementptr inbounds ([30 x i8], [30 x i8]* @__PRETTY_FUNCTION__.star_rectangle, i32 0, i32 0)) #3
  unreachable
                                                  ; No predecessors!
  br label %10

; <label>:10:                                     ; preds = %9, %7
  store i32 1, i32* %h, align 4
  br label %11

; <label>:11:                                     ; preds = %16, %10
  %12 = load i32, i32* %h, align 4
  %13 = load i32, i32* %height.addr, align 4
  %cmp2 = icmp sle i32 %12, %13
  br i1 %cmp2, label %14, label %18

; <label>:14:                                     ; preds = %11
  %15 = load i32, i32* %width.addr, align 4
  call void @star_row(i32 %15)
  br label %16

; <label>:16:                                     ; preds = %14
  %17 = load i32, i32* %h, align 4
  %inc = add nsw i32 %17, 1
  store i32 %inc, i32* %h, align 4
  br label %11

; <label>:18:                                     ; preds = %11
  ret void
}

; Function Attrs: noreturn nounwind
declare void @__assert_fail(i8*, i8*, i32, i8*) #1

; Function Attrs: nounwind
define internal void @star_row(i32 %width) #0 {
  %width.addr = alloca i32, align 4
  %i = alloca i32, align 4
  store i32 %width, i32* %width.addr, align 4
  %1 = load i32, i32* %width.addr, align 4
  %cmp = icmp sge i32 %1, 0
  br i1 %cmp, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([51 x i8], [51 x i8]* @.str.1, i32 0, i32 0), i32 9, i8* getelementptr inbounds ([19 x i8], [19 x i8]* @__PRETTY_FUNCTION__.star_row, i32 0, i32 0)) #3
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  store i32 0, i32* %i, align 4
  br label %6

; <label>:6:                                      ; preds = %10, %5
  %7 = load i32, i32* %i, align 4
  %8 = load i32, i32* %width.addr, align 4
  %cmp1 = icmp slt i32 %7, %8
  br i1 %cmp1, label %9, label %12

; <label>:9:                                      ; preds = %6
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.4, i32 0, i32 0))
  br label %10

; <label>:10:                                     ; preds = %9
  %11 = load i32, i32* %i, align 4
  %inc = add nsw i32 %11, 1
  store i32 %inc, i32* %i, align 4
  br label %6

; <label>:12:                                     ; preds = %6
  %call2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.5, i32 0, i32 0))
  ret void
}

declare i32 @printf(i8*, ...) #2

; Function Attrs: nounwind
define void @star_triangle(i32 %height) #0 {
  %height.addr = alloca i32, align 4
  %h = alloca i32, align 4
  store i32 %height, i32* %height.addr, align 4
  %1 = load i32, i32* %height.addr, align 4
  %cmp = icmp sge i32 %1, 0
  br i1 %cmp, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([51 x i8], [51 x i8]* @.str.1, i32 0, i32 0), i32 46, i8* getelementptr inbounds ([24 x i8], [24 x i8]* @__PRETTY_FUNCTION__.star_triangle, i32 0, i32 0)) #3
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  store i32 1, i32* %h, align 4
  br label %6

; <label>:6:                                      ; preds = %11, %5
  %7 = load i32, i32* %h, align 4
  %8 = load i32, i32* %height.addr, align 4
  %cmp1 = icmp sle i32 %7, %8
  br i1 %cmp1, label %9, label %13

; <label>:9:                                      ; preds = %6
  %10 = load i32, i32* %h, align 4
  call void @star_row(i32 %10)
  br label %11

; <label>:11:                                     ; preds = %9
  %12 = load i32, i32* %h, align 4
  %inc = add nsw i32 %12, 1
  store i32 %inc, i32* %h, align 4
  br label %6

; <label>:13:                                     ; preds = %6
  ret void
}

; Function Attrs: nounwind
define void @star_diamond(i32 %k) #0 {
  %k.addr = alloca i32, align 4
  %i = alloca i32, align 4
  %i3 = alloca i32, align 4
  store i32 %k, i32* %k.addr, align 4
  %1 = load i32, i32* %k.addr, align 4
  %cmp = icmp sgt i32 %1, 0
  br i1 %cmp, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([51 x i8], [51 x i8]* @.str.1, i32 0, i32 0), i32 58, i8* getelementptr inbounds ([23 x i8], [23 x i8]* @__PRETTY_FUNCTION__.star_diamond, i32 0, i32 0)) #3
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  store i32 1, i32* %i, align 4
  br label %6

; <label>:6:                                      ; preds = %13, %5
  %7 = load i32, i32* %i, align 4
  %8 = load i32, i32* %k.addr, align 4
  %cmp1 = icmp sle i32 %7, %8
  br i1 %cmp1, label %9, label %15

; <label>:9:                                      ; preds = %6
  %10 = load i32, i32* %k.addr, align 4
  %11 = load i32, i32* %i, align 4
  %sub = sub nsw i32 %10, %11
  call void @space_row(i32 %sub)
  %12 = load i32, i32* %i, align 4
  %mul = mul nsw i32 %12, 2
  %sub2 = sub nsw i32 %mul, 1
  call void @star_row(i32 %sub2)
  br label %13

; <label>:13:                                     ; preds = %9
  %14 = load i32, i32* %i, align 4
  %inc = add nsw i32 %14, 1
  store i32 %inc, i32* %i, align 4
  br label %6

; <label>:15:                                     ; preds = %6
  %16 = load i32, i32* %k.addr, align 4
  %sub4 = sub nsw i32 %16, 1
  store i32 %sub4, i32* %i3, align 4
  br label %17

; <label>:17:                                     ; preds = %23, %15
  %18 = load i32, i32* %i3, align 4
  %cmp5 = icmp sge i32 %18, 1
  br i1 %cmp5, label %19, label %25

; <label>:19:                                     ; preds = %17
  %20 = load i32, i32* %k.addr, align 4
  %21 = load i32, i32* %i3, align 4
  %sub6 = sub nsw i32 %20, %21
  call void @space_row(i32 %sub6)
  %22 = load i32, i32* %i3, align 4
  %mul7 = mul nsw i32 %22, 2
  %sub8 = sub nsw i32 %mul7, 1
  call void @star_row(i32 %sub8)
  br label %23

; <label>:23:                                     ; preds = %19
  %24 = load i32, i32* %i3, align 4
  %dec = add nsw i32 %24, -1
  store i32 %dec, i32* %i3, align 4
  br label %17

; <label>:25:                                     ; preds = %17
  ret void
}

; Function Attrs: nounwind
define internal void @space_row(i32 %n) #0 {
  %n.addr = alloca i32, align 4
  %i = alloca i32, align 4
  store i32 %n, i32* %n.addr, align 4
  store i32 0, i32* %i, align 4
  br label %1

; <label>:1:                                      ; preds = %5, %0
  %2 = load i32, i32* %i, align 4
  %3 = load i32, i32* %n.addr, align 4
  %cmp = icmp slt i32 %2, %3
  br i1 %cmp, label %4, label %7

; <label>:4:                                      ; preds = %1
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.6, i32 0, i32 0))
  br label %5

; <label>:5:                                      ; preds = %4
  %6 = load i32, i32* %i, align 4
  %inc = add nsw i32 %6, 1
  store i32 %inc, i32* %i, align 4
  br label %1

; <label>:7:                                      ; preds = %1
  ret void
}

; Function Attrs: nounwind
define void @digit_rectangle(i32 %height, i32 %width) #0 {
  %height.addr = alloca i32, align 4
  %width.addr = alloca i32, align 4
  %h = alloca i32, align 4
  store i32 %height, i32* %height.addr, align 4
  store i32 %width, i32* %width.addr, align 4
  %1 = load i32, i32* %height.addr, align 4
  %cmp = icmp sge i32 %1, 0
  br i1 %cmp, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([51 x i8], [51 x i8]* @.str.1, i32 0, i32 0), i32 88, i8* getelementptr inbounds ([31 x i8], [31 x i8]* @__PRETTY_FUNCTION__.digit_rectangle, i32 0, i32 0)) #3
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load i32, i32* %width.addr, align 4
  %cmp1 = icmp sge i32 %6, 0
  br i1 %cmp1, label %7, label %8

; <label>:7:                                      ; preds = %5
  br label %10

; <label>:8:                                      ; preds = %5
  call void @__assert_fail(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([51 x i8], [51 x i8]* @.str.1, i32 0, i32 0), i32 89, i8* getelementptr inbounds ([31 x i8], [31 x i8]* @__PRETTY_FUNCTION__.digit_rectangle, i32 0, i32 0)) #3
  unreachable
                                                  ; No predecessors!
  br label %10

; <label>:10:                                     ; preds = %9, %7
  store i32 1, i32* %h, align 4
  br label %11

; <label>:11:                                     ; preds = %17, %10
  %12 = load i32, i32* %h, align 4
  %13 = load i32, i32* %height.addr, align 4
  %cmp2 = icmp sle i32 %12, %13
  br i1 %cmp2, label %14, label %19

; <label>:14:                                     ; preds = %11
  %15 = load i32, i32* %h, align 4
  %16 = load i32, i32* %width.addr, align 4
  call void @digit_row(i32 %15, i32 %16)
  br label %17

; <label>:17:                                     ; preds = %14
  %18 = load i32, i32* %h, align 4
  %inc = add nsw i32 %18, 1
  store i32 %inc, i32* %h, align 4
  br label %11

; <label>:19:                                     ; preds = %11
  ret void
}

; Function Attrs: nounwind
define internal void @digit_row(i32 %start, i32 %len) #0 {
  %start.addr = alloca i32, align 4
  %len.addr = alloca i32, align 4
  %i = alloca i32, align 4
  store i32 %start, i32* %start.addr, align 4
  store i32 %len, i32* %len.addr, align 4
  store i32 0, i32* %i, align 4
  br label %1

; <label>:1:                                      ; preds = %7, %0
  %2 = load i32, i32* %i, align 4
  %3 = load i32, i32* %len.addr, align 4
  %cmp = icmp slt i32 %2, %3
  br i1 %cmp, label %4, label %9

; <label>:4:                                      ; preds = %1
  %5 = load i32, i32* %start.addr, align 4
  %6 = load i32, i32* %i, align 4
  %add = add nsw i32 %5, %6
  %rem = srem i32 %add, 10
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.7, i32 0, i32 0), i32 %rem)
  br label %7

; <label>:7:                                      ; preds = %4
  %8 = load i32, i32* %i, align 4
  %inc = add nsw i32 %8, 1
  store i32 %inc, i32* %i, align 4
  br label %1

; <label>:9:                                      ; preds = %1
  %call1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.5, i32 0, i32 0))
  ret void
}

; Function Attrs: nounwind
define void @digit_triangle(i32 %height) #0 {
  %height.addr = alloca i32, align 4
  %h = alloca i32, align 4
  store i32 %height, i32* %height.addr, align 4
  %1 = load i32, i32* %height.addr, align 4
  %cmp = icmp sge i32 %1, 0
  br i1 %cmp, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([51 x i8], [51 x i8]* @.str.1, i32 0, i32 0), i32 101, i8* getelementptr inbounds ([25 x i8], [25 x i8]* @__PRETTY_FUNCTION__.digit_triangle, i32 0, i32 0)) #3
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  store i32 1, i32* %h, align 4
  br label %6

; <label>:6:                                      ; preds = %12, %5
  %7 = load i32, i32* %h, align 4
  %8 = load i32, i32* %height.addr, align 4
  %cmp1 = icmp sle i32 %7, %8
  br i1 %cmp1, label %9, label %14

; <label>:9:                                      ; preds = %6
  %10 = load i32, i32* %h, align 4
  %11 = load i32, i32* %h, align 4
  call void @digit_row(i32 %10, i32 %11)
  br label %12

; <label>:12:                                     ; preds = %9
  %13 = load i32, i32* %h, align 4
  %inc = add nsw i32 %13, 1
  store i32 %inc, i32* %h, align 4
  br label %6

; <label>:14:                                     ; preds = %6
  ret void
}

attributes #0 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { noreturn nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noreturn nounwind }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.9.1 "}
