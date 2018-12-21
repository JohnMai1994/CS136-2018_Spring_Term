; ModuleID = 'seashell-compiler-output'
source_filename = "seashell-compiler-output"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.stack = type { i32, i32, i32* }

@.str = private unnamed_addr constant [2 x i8] c"s\00", align 1
@.str.1 = private unnamed_addr constant [52 x i8] c"/u1/dtompkins/.seashell/projects/_A5/common/stack.c\00", align 1
@__PRETTY_FUNCTION__.stack_push = private unnamed_addr constant [37 x i8] c"void stack_push(int, struct stack *)\00", align 1
@__PRETTY_FUNCTION__.stack_is_empty = private unnamed_addr constant [43 x i8] c"_Bool stack_is_empty(const struct stack *)\00", align 1
@__PRETTY_FUNCTION__.stack_top = private unnamed_addr constant [36 x i8] c"int stack_top(const struct stack *)\00", align 1
@.str.2 = private unnamed_addr constant [7 x i8] c"s->len\00", align 1
@__PRETTY_FUNCTION__.stack_pop = private unnamed_addr constant [30 x i8] c"int stack_pop(struct stack *)\00", align 1

; Function Attrs: nounwind
define %struct.stack* @stack_create() #0 {
  %s = alloca %struct.stack*, align 8
  %call = call noalias i8* @malloc(i64 16) #3
  %1 = bitcast i8* %call to %struct.stack*
  store %struct.stack* %1, %struct.stack** %s, align 8
  %2 = load %struct.stack*, %struct.stack** %s, align 8
  %len = getelementptr inbounds %struct.stack, %struct.stack* %2, i32 0, i32 0
  store i32 0, i32* %len, align 8
  %3 = load %struct.stack*, %struct.stack** %s, align 8
  %maxlen = getelementptr inbounds %struct.stack, %struct.stack* %3, i32 0, i32 1
  store i32 1, i32* %maxlen, align 4
  %4 = load %struct.stack*, %struct.stack** %s, align 8
  %maxlen1 = getelementptr inbounds %struct.stack, %struct.stack* %4, i32 0, i32 1
  %5 = load i32, i32* %maxlen1, align 4
  %conv = sext i32 %5 to i64
  %mul = mul i64 %conv, 4
  %call2 = call noalias i8* @malloc(i64 %mul) #3
  %6 = bitcast i8* %call2 to i32*
  %7 = load %struct.stack*, %struct.stack** %s, align 8
  %data = getelementptr inbounds %struct.stack, %struct.stack* %7, i32 0, i32 2
  store i32* %6, i32** %data, align 8
  %8 = load %struct.stack*, %struct.stack** %s, align 8
  ret %struct.stack* %8
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

; Function Attrs: nounwind
define void @stack_push(i32 %item, %struct.stack* %s) #0 {
  %item.addr = alloca i32, align 4
  %s.addr = alloca %struct.stack*, align 8
  store i32 %item, i32* %item.addr, align 4
  store %struct.stack* %s, %struct.stack** %s.addr, align 8
  %1 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %tobool = icmp ne %struct.stack* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 20, i8* getelementptr inbounds ([37 x i8], [37 x i8]* @__PRETTY_FUNCTION__.stack_push, i32 0, i32 0)) #4
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %len = getelementptr inbounds %struct.stack, %struct.stack* %6, i32 0, i32 0
  %7 = load i32, i32* %len, align 8
  %8 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %maxlen = getelementptr inbounds %struct.stack, %struct.stack* %8, i32 0, i32 1
  %9 = load i32, i32* %maxlen, align 4
  %cmp = icmp eq i32 %7, %9
  br i1 %cmp, label %10, label %20

; <label>:10:                                     ; preds = %5
  %11 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %maxlen1 = getelementptr inbounds %struct.stack, %struct.stack* %11, i32 0, i32 1
  %12 = load i32, i32* %maxlen1, align 4
  %mul = mul nsw i32 %12, 2
  store i32 %mul, i32* %maxlen1, align 4
  %13 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %data = getelementptr inbounds %struct.stack, %struct.stack* %13, i32 0, i32 2
  %14 = load i32*, i32** %data, align 8
  %15 = bitcast i32* %14 to i8*
  %16 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %maxlen2 = getelementptr inbounds %struct.stack, %struct.stack* %16, i32 0, i32 1
  %17 = load i32, i32* %maxlen2, align 4
  %conv = sext i32 %17 to i64
  %mul3 = mul i64 %conv, 4
  %call = call i8* @realloc(i8* %15, i64 %mul3) #3
  %18 = bitcast i8* %call to i32*
  %19 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %data4 = getelementptr inbounds %struct.stack, %struct.stack* %19, i32 0, i32 2
  store i32* %18, i32** %data4, align 8
  br label %20

; <label>:20:                                     ; preds = %10, %5
  %21 = load i32, i32* %item.addr, align 4
  %22 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %len5 = getelementptr inbounds %struct.stack, %struct.stack* %22, i32 0, i32 0
  %23 = load i32, i32* %len5, align 8
  %idxprom = sext i32 %23 to i64
  %24 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %data6 = getelementptr inbounds %struct.stack, %struct.stack* %24, i32 0, i32 2
  %25 = load i32*, i32** %data6, align 8
  %arrayidx = getelementptr inbounds i32, i32* %25, i64 %idxprom
  store i32 %21, i32* %arrayidx, align 4
  %26 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %len7 = getelementptr inbounds %struct.stack, %struct.stack* %26, i32 0, i32 0
  %27 = load i32, i32* %len7, align 8
  %add = add nsw i32 %27, 1
  store i32 %add, i32* %len7, align 8
  ret void
}

; Function Attrs: noreturn nounwind
declare void @__assert_fail(i8*, i8*, i32, i8*) #2

; Function Attrs: nounwind
declare i8* @realloc(i8*, i64) #1

; Function Attrs: nounwind
define void @stack_destroy(%struct.stack* %s) #0 {
  %s.addr = alloca %struct.stack*, align 8
  store %struct.stack* %s, %struct.stack** %s.addr, align 8
  %1 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %data = getelementptr inbounds %struct.stack, %struct.stack* %1, i32 0, i32 2
  %2 = load i32*, i32** %data, align 8
  %3 = bitcast i32* %2 to i8*
  call void @free(i8* %3) #3
  %4 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %5 = bitcast %struct.stack* %4 to i8*
  call void @free(i8* %5) #3
  ret void
}

; Function Attrs: nounwind
declare void @free(i8*) #1

; Function Attrs: nounwind
define zeroext i1 @stack_is_empty(%struct.stack* %s) #0 {
  %s.addr = alloca %struct.stack*, align 8
  store %struct.stack* %s, %struct.stack** %s.addr, align 8
  %1 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %tobool = icmp ne %struct.stack* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 35, i8* getelementptr inbounds ([43 x i8], [43 x i8]* @__PRETTY_FUNCTION__.stack_is_empty, i32 0, i32 0)) #4
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %len = getelementptr inbounds %struct.stack, %struct.stack* %6, i32 0, i32 0
  %7 = load i32, i32* %len, align 8
  %cmp = icmp eq i32 %7, 0
  ret i1 %cmp
}

; Function Attrs: nounwind
define i32 @stack_top(%struct.stack* %s) #0 {
  %s.addr = alloca %struct.stack*, align 8
  store %struct.stack* %s, %struct.stack** %s.addr, align 8
  %1 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %tobool = icmp ne %struct.stack* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 40, i8* getelementptr inbounds ([36 x i8], [36 x i8]* @__PRETTY_FUNCTION__.stack_top, i32 0, i32 0)) #4
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %len = getelementptr inbounds %struct.stack, %struct.stack* %6, i32 0, i32 0
  %7 = load i32, i32* %len, align 8
  %tobool1 = icmp ne i32 %7, 0
  br i1 %tobool1, label %8, label %9

; <label>:8:                                      ; preds = %5
  br label %11

; <label>:9:                                      ; preds = %5
  call void @__assert_fail(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 41, i8* getelementptr inbounds ([36 x i8], [36 x i8]* @__PRETTY_FUNCTION__.stack_top, i32 0, i32 0)) #4
  unreachable
                                                  ; No predecessors!
  br label %11

; <label>:11:                                     ; preds = %10, %8
  %12 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %len2 = getelementptr inbounds %struct.stack, %struct.stack* %12, i32 0, i32 0
  %13 = load i32, i32* %len2, align 8
  %sub = sub nsw i32 %13, 1
  %idxprom = sext i32 %sub to i64
  %14 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %data = getelementptr inbounds %struct.stack, %struct.stack* %14, i32 0, i32 2
  %15 = load i32*, i32** %data, align 8
  %arrayidx = getelementptr inbounds i32, i32* %15, i64 %idxprom
  %16 = load i32, i32* %arrayidx, align 4
  ret i32 %16
}

; Function Attrs: nounwind
define i32 @stack_pop(%struct.stack* %s) #0 {
  %s.addr = alloca %struct.stack*, align 8
  store %struct.stack* %s, %struct.stack** %s.addr, align 8
  %1 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %tobool = icmp ne %struct.stack* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 46, i8* getelementptr inbounds ([30 x i8], [30 x i8]* @__PRETTY_FUNCTION__.stack_pop, i32 0, i32 0)) #4
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %len = getelementptr inbounds %struct.stack, %struct.stack* %6, i32 0, i32 0
  %7 = load i32, i32* %len, align 8
  %tobool1 = icmp ne i32 %7, 0
  br i1 %tobool1, label %8, label %9

; <label>:8:                                      ; preds = %5
  br label %11

; <label>:9:                                      ; preds = %5
  call void @__assert_fail(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([52 x i8], [52 x i8]* @.str.1, i32 0, i32 0), i32 47, i8* getelementptr inbounds ([30 x i8], [30 x i8]* @__PRETTY_FUNCTION__.stack_pop, i32 0, i32 0)) #4
  unreachable
                                                  ; No predecessors!
  br label %11

; <label>:11:                                     ; preds = %10, %8
  %12 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %len2 = getelementptr inbounds %struct.stack, %struct.stack* %12, i32 0, i32 0
  %13 = load i32, i32* %len2, align 8
  %sub = sub nsw i32 %13, 1
  store i32 %sub, i32* %len2, align 8
  %14 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %len3 = getelementptr inbounds %struct.stack, %struct.stack* %14, i32 0, i32 0
  %15 = load i32, i32* %len3, align 8
  %idxprom = sext i32 %15 to i64
  %16 = load %struct.stack*, %struct.stack** %s.addr, align 8
  %data = getelementptr inbounds %struct.stack, %struct.stack* %16, i32 0, i32 2
  %17 = load i32*, i32** %data, align 8
  %arrayidx = getelementptr inbounds i32, i32* %17, i64 %idxprom
  %18 = load i32, i32* %arrayidx, align 4
  ret i32 %18
}

attributes #0 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noreturn nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }
attributes #4 = { noreturn nounwind }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.9.1 "}
