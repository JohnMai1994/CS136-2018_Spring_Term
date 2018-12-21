; ModuleID = 'seashell-compiler-output'
source_filename = "seashell-compiler-output"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.destack = type { %struct.dllnode*, %struct.dllnode* }
%struct.dllnode = type { i32, %struct.dllnode*, %struct.dllnode* }

@.str = private unnamed_addr constant [2 x i8] c"s\00", align 1
@.str.1 = private unnamed_addr constant [59 x i8] c"/u7/pkindermann/.seashell/projects/_Draft-A9/q2c/destack.c\00", align 1
@__PRETTY_FUNCTION__.destack_is_empty = private unnamed_addr constant [47 x i8] c"_Bool destack_is_empty(const struct destack *)\00", align 1
@__PRETTY_FUNCTION__.destack_bot = private unnamed_addr constant [40 x i8] c"int destack_bot(const struct destack *)\00", align 1
@.str.2 = private unnamed_addr constant [7 x i8] c"s->bot\00", align 1
@__PRETTY_FUNCTION__.destack_top = private unnamed_addr constant [40 x i8] c"int destack_top(const struct destack *)\00", align 1
@__PRETTY_FUNCTION__.destack_pop_bot = private unnamed_addr constant [38 x i8] c"int destack_pop_bot(struct destack *)\00", align 1
@__PRETTY_FUNCTION__.destack_pop_top = private unnamed_addr constant [38 x i8] c"int destack_pop_top(struct destack *)\00", align 1
@__PRETTY_FUNCTION__.destack_push_bot = private unnamed_addr constant [45 x i8] c"void destack_push_bot(int, struct destack *)\00", align 1
@__PRETTY_FUNCTION__.destack_push_top = private unnamed_addr constant [45 x i8] c"void destack_push_top(int, struct destack *)\00", align 1
@__PRETTY_FUNCTION__.destack_destroy = private unnamed_addr constant [39 x i8] c"void destack_destroy(struct destack *)\00", align 1
@__PRETTY_FUNCTION__.destack_print = private unnamed_addr constant [43 x i8] c"void destack_print(const struct destack *)\00", align 1
@.str.3 = private unnamed_addr constant [10 x i8] c"Destack:\0A\00", align 1
@.str.4 = private unnamed_addr constant [8 x i8] c"Bot -> \00", align 1
@.str.5 = private unnamed_addr constant [7 x i8] c"%d -> \00", align 1
@.str.6 = private unnamed_addr constant [6 x i8] c"NULL\0A\00", align 1
@.str.7 = private unnamed_addr constant [8 x i8] c"Top -> \00", align 1

; Function Attrs: nounwind
define %struct.destack* @destack_create() #0 {
  %s = alloca %struct.destack*, align 8
  %call = call noalias i8* @malloc(i64 16) #4
  %1 = bitcast i8* %call to %struct.destack*
  store %struct.destack* %1, %struct.destack** %s, align 8
  %2 = load %struct.destack*, %struct.destack** %s, align 8
  %bot = getelementptr inbounds %struct.destack, %struct.destack* %2, i32 0, i32 0
  store %struct.dllnode* null, %struct.dllnode** %bot, align 8
  %3 = load %struct.destack*, %struct.destack** %s, align 8
  %top = getelementptr inbounds %struct.destack, %struct.destack* %3, i32 0, i32 1
  store %struct.dllnode* null, %struct.dllnode** %top, align 8
  %4 = load %struct.destack*, %struct.destack** %s, align 8
  ret %struct.destack* %4
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

; Function Attrs: nounwind
define zeroext i1 @destack_is_empty(%struct.destack* %s) #0 {
  %s.addr = alloca %struct.destack*, align 8
  store %struct.destack* %s, %struct.destack** %s.addr, align 8
  %1 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %tobool = icmp ne %struct.destack* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([59 x i8], [59 x i8]* @.str.1, i32 0, i32 0), i32 36, i8* getelementptr inbounds ([47 x i8], [47 x i8]* @__PRETTY_FUNCTION__.destack_is_empty, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot = getelementptr inbounds %struct.destack, %struct.destack* %6, i32 0, i32 0
  %7 = load %struct.dllnode*, %struct.dllnode** %bot, align 8
  %tobool1 = icmp ne %struct.dllnode* %7, null
  %lnot = xor i1 %tobool1, true
  ret i1 %lnot
}

; Function Attrs: noreturn nounwind
declare void @__assert_fail(i8*, i8*, i32, i8*) #2

; Function Attrs: nounwind
define i32 @destack_bot(%struct.destack* %s) #0 {
  %s.addr = alloca %struct.destack*, align 8
  store %struct.destack* %s, %struct.destack** %s.addr, align 8
  %1 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %tobool = icmp ne %struct.destack* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([59 x i8], [59 x i8]* @.str.1, i32 0, i32 0), i32 44, i8* getelementptr inbounds ([40 x i8], [40 x i8]* @__PRETTY_FUNCTION__.destack_bot, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot = getelementptr inbounds %struct.destack, %struct.destack* %6, i32 0, i32 0
  %7 = load %struct.dllnode*, %struct.dllnode** %bot, align 8
  %tobool1 = icmp ne %struct.dllnode* %7, null
  br i1 %tobool1, label %8, label %9

; <label>:8:                                      ; preds = %5
  br label %11

; <label>:9:                                      ; preds = %5
  call void @__assert_fail(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([59 x i8], [59 x i8]* @.str.1, i32 0, i32 0), i32 45, i8* getelementptr inbounds ([40 x i8], [40 x i8]* @__PRETTY_FUNCTION__.destack_bot, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %11

; <label>:11:                                     ; preds = %10, %8
  %12 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot2 = getelementptr inbounds %struct.destack, %struct.destack* %12, i32 0, i32 0
  %13 = load %struct.dllnode*, %struct.dllnode** %bot2, align 8
  %item = getelementptr inbounds %struct.dllnode, %struct.dllnode* %13, i32 0, i32 0
  %14 = load i32, i32* %item, align 8
  ret i32 %14
}

; Function Attrs: nounwind
define i32 @destack_top(%struct.destack* %s) #0 {
  %s.addr = alloca %struct.destack*, align 8
  store %struct.destack* %s, %struct.destack** %s.addr, align 8
  %1 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %tobool = icmp ne %struct.destack* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([59 x i8], [59 x i8]* @.str.1, i32 0, i32 0), i32 53, i8* getelementptr inbounds ([40 x i8], [40 x i8]* @__PRETTY_FUNCTION__.destack_top, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot = getelementptr inbounds %struct.destack, %struct.destack* %6, i32 0, i32 0
  %7 = load %struct.dllnode*, %struct.dllnode** %bot, align 8
  %tobool1 = icmp ne %struct.dllnode* %7, null
  br i1 %tobool1, label %8, label %9

; <label>:8:                                      ; preds = %5
  br label %11

; <label>:9:                                      ; preds = %5
  call void @__assert_fail(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([59 x i8], [59 x i8]* @.str.1, i32 0, i32 0), i32 54, i8* getelementptr inbounds ([40 x i8], [40 x i8]* @__PRETTY_FUNCTION__.destack_top, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %11

; <label>:11:                                     ; preds = %10, %8
  %12 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %top = getelementptr inbounds %struct.destack, %struct.destack* %12, i32 0, i32 1
  %13 = load %struct.dllnode*, %struct.dllnode** %top, align 8
  %item = getelementptr inbounds %struct.dllnode, %struct.dllnode* %13, i32 0, i32 0
  %14 = load i32, i32* %item, align 8
  ret i32 %14
}

; Function Attrs: nounwind
define i32 @destack_pop_bot(%struct.destack* %s) #0 {
  %s.addr = alloca %struct.destack*, align 8
  %botitem = alloca i32, align 4
  %temp = alloca %struct.dllnode*, align 8
  store %struct.destack* %s, %struct.destack** %s.addr, align 8
  %1 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %tobool = icmp ne %struct.destack* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([59 x i8], [59 x i8]* @.str.1, i32 0, i32 0), i32 63, i8* getelementptr inbounds ([38 x i8], [38 x i8]* @__PRETTY_FUNCTION__.destack_pop_bot, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot = getelementptr inbounds %struct.destack, %struct.destack* %6, i32 0, i32 0
  %7 = load %struct.dllnode*, %struct.dllnode** %bot, align 8
  %tobool1 = icmp ne %struct.dllnode* %7, null
  br i1 %tobool1, label %8, label %9

; <label>:8:                                      ; preds = %5
  br label %11

; <label>:9:                                      ; preds = %5
  call void @__assert_fail(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([59 x i8], [59 x i8]* @.str.1, i32 0, i32 0), i32 64, i8* getelementptr inbounds ([38 x i8], [38 x i8]* @__PRETTY_FUNCTION__.destack_pop_bot, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %11

; <label>:11:                                     ; preds = %10, %8
  %12 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot2 = getelementptr inbounds %struct.destack, %struct.destack* %12, i32 0, i32 0
  %13 = load %struct.dllnode*, %struct.dllnode** %bot2, align 8
  %item = getelementptr inbounds %struct.dllnode, %struct.dllnode* %13, i32 0, i32 0
  %14 = load i32, i32* %item, align 8
  store i32 %14, i32* %botitem, align 4
  %15 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot3 = getelementptr inbounds %struct.destack, %struct.destack* %15, i32 0, i32 0
  %16 = load %struct.dllnode*, %struct.dllnode** %bot3, align 8
  store %struct.dllnode* %16, %struct.dllnode** %temp, align 8
  %17 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot4 = getelementptr inbounds %struct.destack, %struct.destack* %17, i32 0, i32 0
  %18 = load %struct.dllnode*, %struct.dllnode** %bot4, align 8
  %next = getelementptr inbounds %struct.dllnode, %struct.dllnode* %18, i32 0, i32 2
  %19 = load %struct.dllnode*, %struct.dllnode** %next, align 8
  %20 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot5 = getelementptr inbounds %struct.destack, %struct.destack* %20, i32 0, i32 0
  store %struct.dllnode* %19, %struct.dllnode** %bot5, align 8
  %21 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot6 = getelementptr inbounds %struct.destack, %struct.destack* %21, i32 0, i32 0
  %22 = load %struct.dllnode*, %struct.dllnode** %bot6, align 8
  %tobool7 = icmp ne %struct.dllnode* %22, null
  br i1 %tobool7, label %23, label %26

; <label>:23:                                     ; preds = %11
  %24 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot8 = getelementptr inbounds %struct.destack, %struct.destack* %24, i32 0, i32 0
  %25 = load %struct.dllnode*, %struct.dllnode** %bot8, align 8
  %prev = getelementptr inbounds %struct.dllnode, %struct.dllnode* %25, i32 0, i32 1
  store %struct.dllnode* null, %struct.dllnode** %prev, align 8
  br label %28

; <label>:26:                                     ; preds = %11
  %27 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %top = getelementptr inbounds %struct.destack, %struct.destack* %27, i32 0, i32 1
  store %struct.dllnode* null, %struct.dllnode** %top, align 8
  br label %28

; <label>:28:                                     ; preds = %26, %23
  %29 = load %struct.dllnode*, %struct.dllnode** %temp, align 8
  %30 = bitcast %struct.dllnode* %29 to i8*
  call void @free(i8* %30) #4
  %31 = load i32, i32* %botitem, align 4
  ret i32 %31
}

; Function Attrs: nounwind
declare void @free(i8*) #1

; Function Attrs: nounwind
define i32 @destack_pop_top(%struct.destack* %s) #0 {
  %s.addr = alloca %struct.destack*, align 8
  %topitem = alloca i32, align 4
  %temp = alloca %struct.dllnode*, align 8
  store %struct.destack* %s, %struct.destack** %s.addr, align 8
  %1 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %tobool = icmp ne %struct.destack* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([59 x i8], [59 x i8]* @.str.1, i32 0, i32 0), i32 82, i8* getelementptr inbounds ([38 x i8], [38 x i8]* @__PRETTY_FUNCTION__.destack_pop_top, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot = getelementptr inbounds %struct.destack, %struct.destack* %6, i32 0, i32 0
  %7 = load %struct.dllnode*, %struct.dllnode** %bot, align 8
  %tobool1 = icmp ne %struct.dllnode* %7, null
  br i1 %tobool1, label %8, label %9

; <label>:8:                                      ; preds = %5
  br label %11

; <label>:9:                                      ; preds = %5
  call void @__assert_fail(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([59 x i8], [59 x i8]* @.str.1, i32 0, i32 0), i32 83, i8* getelementptr inbounds ([38 x i8], [38 x i8]* @__PRETTY_FUNCTION__.destack_pop_top, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %11

; <label>:11:                                     ; preds = %10, %8
  %12 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %top = getelementptr inbounds %struct.destack, %struct.destack* %12, i32 0, i32 1
  %13 = load %struct.dllnode*, %struct.dllnode** %top, align 8
  %item = getelementptr inbounds %struct.dllnode, %struct.dllnode* %13, i32 0, i32 0
  %14 = load i32, i32* %item, align 8
  store i32 %14, i32* %topitem, align 4
  %15 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %top2 = getelementptr inbounds %struct.destack, %struct.destack* %15, i32 0, i32 1
  %16 = load %struct.dllnode*, %struct.dllnode** %top2, align 8
  store %struct.dllnode* %16, %struct.dllnode** %temp, align 8
  %17 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %top3 = getelementptr inbounds %struct.destack, %struct.destack* %17, i32 0, i32 1
  %18 = load %struct.dllnode*, %struct.dllnode** %top3, align 8
  %prev = getelementptr inbounds %struct.dllnode, %struct.dllnode* %18, i32 0, i32 1
  %19 = load %struct.dllnode*, %struct.dllnode** %prev, align 8
  %20 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %top4 = getelementptr inbounds %struct.destack, %struct.destack* %20, i32 0, i32 1
  store %struct.dllnode* %19, %struct.dllnode** %top4, align 8
  %21 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %top5 = getelementptr inbounds %struct.destack, %struct.destack* %21, i32 0, i32 1
  %22 = load %struct.dllnode*, %struct.dllnode** %top5, align 8
  %tobool6 = icmp ne %struct.dllnode* %22, null
  br i1 %tobool6, label %23, label %26

; <label>:23:                                     ; preds = %11
  %24 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %top7 = getelementptr inbounds %struct.destack, %struct.destack* %24, i32 0, i32 1
  %25 = load %struct.dllnode*, %struct.dllnode** %top7, align 8
  %next = getelementptr inbounds %struct.dllnode, %struct.dllnode* %25, i32 0, i32 2
  store %struct.dllnode* null, %struct.dllnode** %next, align 8
  br label %28

; <label>:26:                                     ; preds = %11
  %27 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot8 = getelementptr inbounds %struct.destack, %struct.destack* %27, i32 0, i32 0
  store %struct.dllnode* null, %struct.dllnode** %bot8, align 8
  br label %28

; <label>:28:                                     ; preds = %26, %23
  %29 = load %struct.dllnode*, %struct.dllnode** %temp, align 8
  %30 = bitcast %struct.dllnode* %29 to i8*
  call void @free(i8* %30) #4
  %31 = load i32, i32* %topitem, align 4
  ret i32 %31
}

; Function Attrs: nounwind
define void @destack_push_bot(i32 %item, %struct.destack* %s) #0 {
  %item.addr = alloca i32, align 4
  %s.addr = alloca %struct.destack*, align 8
  %node = alloca %struct.dllnode*, align 8
  store i32 %item, i32* %item.addr, align 4
  store %struct.destack* %s, %struct.destack** %s.addr, align 8
  %1 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %tobool = icmp ne %struct.destack* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([59 x i8], [59 x i8]* @.str.1, i32 0, i32 0), i32 100, i8* getelementptr inbounds ([45 x i8], [45 x i8]* @__PRETTY_FUNCTION__.destack_push_bot, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %call = call noalias i8* @malloc(i64 24) #4
  %6 = bitcast i8* %call to %struct.dllnode*
  store %struct.dllnode* %6, %struct.dllnode** %node, align 8
  %7 = load i32, i32* %item.addr, align 4
  %8 = load %struct.dllnode*, %struct.dllnode** %node, align 8
  %item1 = getelementptr inbounds %struct.dllnode, %struct.dllnode* %8, i32 0, i32 0
  store i32 %7, i32* %item1, align 8
  %9 = load %struct.dllnode*, %struct.dllnode** %node, align 8
  %prev = getelementptr inbounds %struct.dllnode, %struct.dllnode* %9, i32 0, i32 1
  store %struct.dllnode* null, %struct.dllnode** %prev, align 8
  %10 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot = getelementptr inbounds %struct.destack, %struct.destack* %10, i32 0, i32 0
  %11 = load %struct.dllnode*, %struct.dllnode** %bot, align 8
  %12 = load %struct.dllnode*, %struct.dllnode** %node, align 8
  %next = getelementptr inbounds %struct.dllnode, %struct.dllnode* %12, i32 0, i32 2
  store %struct.dllnode* %11, %struct.dllnode** %next, align 8
  %13 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot2 = getelementptr inbounds %struct.destack, %struct.destack* %13, i32 0, i32 0
  %14 = load %struct.dllnode*, %struct.dllnode** %bot2, align 8
  %tobool3 = icmp ne %struct.dllnode* %14, null
  br i1 %tobool3, label %15, label %19

; <label>:15:                                     ; preds = %5
  %16 = load %struct.dllnode*, %struct.dllnode** %node, align 8
  %17 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot4 = getelementptr inbounds %struct.destack, %struct.destack* %17, i32 0, i32 0
  %18 = load %struct.dllnode*, %struct.dllnode** %bot4, align 8
  %prev5 = getelementptr inbounds %struct.dllnode, %struct.dllnode* %18, i32 0, i32 1
  store %struct.dllnode* %16, %struct.dllnode** %prev5, align 8
  br label %19

; <label>:19:                                     ; preds = %15, %5
  %20 = load %struct.dllnode*, %struct.dllnode** %node, align 8
  %21 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot6 = getelementptr inbounds %struct.destack, %struct.destack* %21, i32 0, i32 0
  store %struct.dllnode* %20, %struct.dllnode** %bot6, align 8
  %22 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %top = getelementptr inbounds %struct.destack, %struct.destack* %22, i32 0, i32 1
  %23 = load %struct.dllnode*, %struct.dllnode** %top, align 8
  %tobool7 = icmp ne %struct.dllnode* %23, null
  br i1 %tobool7, label %27, label %24

; <label>:24:                                     ; preds = %19
  %25 = load %struct.dllnode*, %struct.dllnode** %node, align 8
  %26 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %top8 = getelementptr inbounds %struct.destack, %struct.destack* %26, i32 0, i32 1
  store %struct.dllnode* %25, %struct.dllnode** %top8, align 8
  br label %27

; <label>:27:                                     ; preds = %24, %19
  ret void
}

; Function Attrs: nounwind
define void @destack_push_top(i32 %item, %struct.destack* %s) #0 {
  %item.addr = alloca i32, align 4
  %s.addr = alloca %struct.destack*, align 8
  %node = alloca %struct.dllnode*, align 8
  store i32 %item, i32* %item.addr, align 4
  store %struct.destack* %s, %struct.destack** %s.addr, align 8
  %1 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %tobool = icmp ne %struct.destack* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([59 x i8], [59 x i8]* @.str.1, i32 0, i32 0), i32 118, i8* getelementptr inbounds ([45 x i8], [45 x i8]* @__PRETTY_FUNCTION__.destack_push_top, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %call = call noalias i8* @malloc(i64 24) #4
  %6 = bitcast i8* %call to %struct.dllnode*
  store %struct.dllnode* %6, %struct.dllnode** %node, align 8
  %7 = load i32, i32* %item.addr, align 4
  %8 = load %struct.dllnode*, %struct.dllnode** %node, align 8
  %item1 = getelementptr inbounds %struct.dllnode, %struct.dllnode* %8, i32 0, i32 0
  store i32 %7, i32* %item1, align 8
  %9 = load %struct.dllnode*, %struct.dllnode** %node, align 8
  %next = getelementptr inbounds %struct.dllnode, %struct.dllnode* %9, i32 0, i32 2
  store %struct.dllnode* null, %struct.dllnode** %next, align 8
  %10 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %top = getelementptr inbounds %struct.destack, %struct.destack* %10, i32 0, i32 1
  %11 = load %struct.dllnode*, %struct.dllnode** %top, align 8
  %12 = load %struct.dllnode*, %struct.dllnode** %node, align 8
  %prev = getelementptr inbounds %struct.dllnode, %struct.dllnode* %12, i32 0, i32 1
  store %struct.dllnode* %11, %struct.dllnode** %prev, align 8
  %13 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %top2 = getelementptr inbounds %struct.destack, %struct.destack* %13, i32 0, i32 1
  %14 = load %struct.dllnode*, %struct.dllnode** %top2, align 8
  %tobool3 = icmp ne %struct.dllnode* %14, null
  br i1 %tobool3, label %15, label %19

; <label>:15:                                     ; preds = %5
  %16 = load %struct.dllnode*, %struct.dllnode** %node, align 8
  %17 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %top4 = getelementptr inbounds %struct.destack, %struct.destack* %17, i32 0, i32 1
  %18 = load %struct.dllnode*, %struct.dllnode** %top4, align 8
  %next5 = getelementptr inbounds %struct.dllnode, %struct.dllnode* %18, i32 0, i32 2
  store %struct.dllnode* %16, %struct.dllnode** %next5, align 8
  br label %19

; <label>:19:                                     ; preds = %15, %5
  %20 = load %struct.dllnode*, %struct.dllnode** %node, align 8
  %21 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %top6 = getelementptr inbounds %struct.destack, %struct.destack* %21, i32 0, i32 1
  store %struct.dllnode* %20, %struct.dllnode** %top6, align 8
  %22 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot = getelementptr inbounds %struct.destack, %struct.destack* %22, i32 0, i32 0
  %23 = load %struct.dllnode*, %struct.dllnode** %bot, align 8
  %tobool7 = icmp ne %struct.dllnode* %23, null
  br i1 %tobool7, label %27, label %24

; <label>:24:                                     ; preds = %19
  %25 = load %struct.dllnode*, %struct.dllnode** %node, align 8
  %26 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot8 = getelementptr inbounds %struct.destack, %struct.destack* %26, i32 0, i32 0
  store %struct.dllnode* %25, %struct.dllnode** %bot8, align 8
  br label %27

; <label>:27:                                     ; preds = %24, %19
  ret void
}

; Function Attrs: nounwind
define void @destack_destroy(%struct.destack* %s) #0 {
  %s.addr = alloca %struct.destack*, align 8
  %temp = alloca %struct.dllnode*, align 8
  store %struct.destack* %s, %struct.destack** %s.addr, align 8
  %1 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %tobool = icmp ne %struct.destack* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([59 x i8], [59 x i8]* @.str.1, i32 0, i32 0), i32 136, i8* getelementptr inbounds ([39 x i8], [39 x i8]* @__PRETTY_FUNCTION__.destack_destroy, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot = getelementptr inbounds %struct.destack, %struct.destack* %6, i32 0, i32 0
  %7 = load %struct.dllnode*, %struct.dllnode** %bot, align 8
  %tobool1 = icmp ne %struct.dllnode* %7, null
  br i1 %tobool1, label %8, label %27

; <label>:8:                                      ; preds = %5
  %9 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot2 = getelementptr inbounds %struct.destack, %struct.destack* %9, i32 0, i32 0
  %10 = load %struct.dllnode*, %struct.dllnode** %bot2, align 8
  %next = getelementptr inbounds %struct.dllnode, %struct.dllnode* %10, i32 0, i32 2
  %11 = load %struct.dllnode*, %struct.dllnode** %next, align 8
  store %struct.dllnode* %11, %struct.dllnode** %temp, align 8
  %12 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot3 = getelementptr inbounds %struct.destack, %struct.destack* %12, i32 0, i32 0
  %13 = load %struct.dllnode*, %struct.dllnode** %bot3, align 8
  %14 = bitcast %struct.dllnode* %13 to i8*
  call void @free(i8* %14) #4
  br label %15

; <label>:15:                                     ; preds = %17, %8
  %16 = load %struct.dllnode*, %struct.dllnode** %temp, align 8
  %tobool4 = icmp ne %struct.dllnode* %16, null
  br i1 %tobool4, label %17, label %26

; <label>:17:                                     ; preds = %15
  %18 = load %struct.dllnode*, %struct.dllnode** %temp, align 8
  %19 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot5 = getelementptr inbounds %struct.destack, %struct.destack* %19, i32 0, i32 0
  store %struct.dllnode* %18, %struct.dllnode** %bot5, align 8
  %20 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot6 = getelementptr inbounds %struct.destack, %struct.destack* %20, i32 0, i32 0
  %21 = load %struct.dllnode*, %struct.dllnode** %bot6, align 8
  %next7 = getelementptr inbounds %struct.dllnode, %struct.dllnode* %21, i32 0, i32 2
  %22 = load %struct.dllnode*, %struct.dllnode** %next7, align 8
  store %struct.dllnode* %22, %struct.dllnode** %temp, align 8
  %23 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot8 = getelementptr inbounds %struct.destack, %struct.destack* %23, i32 0, i32 0
  %24 = load %struct.dllnode*, %struct.dllnode** %bot8, align 8
  %25 = bitcast %struct.dllnode* %24 to i8*
  call void @free(i8* %25) #4
  br label %15

; <label>:26:                                     ; preds = %15
  br label %27

; <label>:27:                                     ; preds = %26, %5
  %28 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %29 = bitcast %struct.destack* %28 to i8*
  call void @free(i8* %29) #4
  ret void
}

; Function Attrs: nounwind
define void @destack_print(%struct.destack* %s) #0 {
  %s.addr = alloca %struct.destack*, align 8
  %temp = alloca %struct.dllnode*, align 8
  store %struct.destack* %s, %struct.destack** %s.addr, align 8
  %1 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %tobool = icmp ne %struct.destack* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([59 x i8], [59 x i8]* @.str.1, i32 0, i32 0), i32 154, i8* getelementptr inbounds ([43 x i8], [43 x i8]* @__PRETTY_FUNCTION__.destack_print, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %bot = getelementptr inbounds %struct.destack, %struct.destack* %6, i32 0, i32 0
  %7 = load %struct.dllnode*, %struct.dllnode** %bot, align 8
  store %struct.dllnode* %7, %struct.dllnode** %temp, align 8
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @.str.3, i32 0, i32 0))
  %call1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @.str.4, i32 0, i32 0))
  br label %8

; <label>:8:                                      ; preds = %10, %5
  %9 = load %struct.dllnode*, %struct.dllnode** %temp, align 8
  %tobool2 = icmp ne %struct.dllnode* %9, null
  br i1 %tobool2, label %10, label %15

; <label>:10:                                     ; preds = %8
  %11 = load %struct.dllnode*, %struct.dllnode** %temp, align 8
  %item = getelementptr inbounds %struct.dllnode, %struct.dllnode* %11, i32 0, i32 0
  %12 = load i32, i32* %item, align 8
  %call3 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.5, i32 0, i32 0), i32 %12)
  %13 = load %struct.dllnode*, %struct.dllnode** %temp, align 8
  %next = getelementptr inbounds %struct.dllnode, %struct.dllnode* %13, i32 0, i32 2
  %14 = load %struct.dllnode*, %struct.dllnode** %next, align 8
  store %struct.dllnode* %14, %struct.dllnode** %temp, align 8
  br label %8

; <label>:15:                                     ; preds = %8
  %call4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.6, i32 0, i32 0))
  %16 = load %struct.destack*, %struct.destack** %s.addr, align 8
  %top = getelementptr inbounds %struct.destack, %struct.destack* %16, i32 0, i32 1
  %17 = load %struct.dllnode*, %struct.dllnode** %top, align 8
  store %struct.dllnode* %17, %struct.dllnode** %temp, align 8
  %call5 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @.str.7, i32 0, i32 0))
  br label %18

; <label>:18:                                     ; preds = %20, %15
  %19 = load %struct.dllnode*, %struct.dllnode** %temp, align 8
  %tobool6 = icmp ne %struct.dllnode* %19, null
  br i1 %tobool6, label %20, label %25

; <label>:20:                                     ; preds = %18
  %21 = load %struct.dllnode*, %struct.dllnode** %temp, align 8
  %item7 = getelementptr inbounds %struct.dllnode, %struct.dllnode* %21, i32 0, i32 0
  %22 = load i32, i32* %item7, align 8
  %call8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.5, i32 0, i32 0), i32 %22)
  %23 = load %struct.dllnode*, %struct.dllnode** %temp, align 8
  %prev = getelementptr inbounds %struct.dllnode, %struct.dllnode* %23, i32 0, i32 1
  %24 = load %struct.dllnode*, %struct.dllnode** %prev, align 8
  store %struct.dllnode* %24, %struct.dllnode** %temp, align 8
  br label %18

; <label>:25:                                     ; preds = %18
  %call9 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str.6, i32 0, i32 0))
  ret void
}

declare i32 @printf(i8*, ...) #3

attributes #0 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noreturn nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind }
attributes #5 = { noreturn nounwind }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.9.1 "}
