; ModuleID = 'seashell-compiler-output'
source_filename = "seashell-compiler-output"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.maze = type { i32, i32, i32, i32, i32, i32, i32, i32, i8* }

@UP = constant i32 0, align 4
@RIGHT = constant i32 1, align 4
@DOWN = constant i32 2, align 4
@LEFT = constant i32 3, align 4
@.str = private unnamed_addr constant [2 x i8] c"m\00", align 1
@.str.1 = private unnamed_addr constant [47 x i8] c"/u1/dtompkins/.seashell/projects/_A5/q4/maze.c\00", align 1
@__PRETTY_FUNCTION__.is_wall = private unnamed_addr constant [40 x i8] c"_Bool is_wall(const struct maze *, int)\00", align 1
@.str.2 = private unnamed_addr constant [80 x i8] c"direction == UP || direction == DOWN || direction == LEFT || direction == RIGHT\00", align 1
@.str.12 = private unnamed_addr constant [20 x i8] c"INVALID MAZE INPUT\0A\00", align 1
@__PRETTY_FUNCTION__.move = private unnamed_addr constant [30 x i8] c"void move(struct maze *, int)\00", align 1
@.str.3 = private unnamed_addr constant [13 x i8] c"***BONK!***\0A\00", align 1
@.str.4 = private unnamed_addr constant [2 x i8] c"U\00", align 1
@.str.5 = private unnamed_addr constant [2 x i8] c"D\00", align 1
@.str.6 = private unnamed_addr constant [2 x i8] c"L\00", align 1
@.str.7 = private unnamed_addr constant [2 x i8] c"R\00", align 1
@.str.8 = private unnamed_addr constant [35 x i8] c"***OUTSIDE MAZE! (unexpected)!***\0A\00", align 1
@.str.9 = private unnamed_addr constant [3 x i8] c"E\0A\00", align 1
@.str.10 = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.11 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@bigbuffer = internal global [1049600 x i8] zeroinitializer, align 16

; Function Attrs: nounwind
define zeroext i1 @is_wall(%struct.maze* %m, i32 %direction) #0 {
  %retval = alloca i1, align 1
  %m.addr = alloca %struct.maze*, align 8
  %direction.addr = alloca i32, align 4
  %position = alloca i8*, align 8
  store %struct.maze* %m, %struct.maze** %m.addr, align 8
  store i32 %direction, i32* %direction.addr, align 4
  %1 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %tobool = icmp ne %struct.maze* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([47 x i8], [47 x i8]* @.str.1, i32 0, i32 0), i32 45, i8* getelementptr inbounds ([40 x i8], [40 x i8]* @__PRETTY_FUNCTION__.is_wall, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load i32, i32* %direction.addr, align 4
  %cmp = icmp eq i32 %6, 0
  br i1 %cmp, label %13, label %7

; <label>:7:                                      ; preds = %5
  %8 = load i32, i32* %direction.addr, align 4
  %cmp1 = icmp eq i32 %8, 2
  br i1 %cmp1, label %13, label %9

; <label>:9:                                      ; preds = %7
  %10 = load i32, i32* %direction.addr, align 4
  %cmp2 = icmp eq i32 %10, 3
  br i1 %cmp2, label %13, label %11

; <label>:11:                                     ; preds = %9
  %12 = load i32, i32* %direction.addr, align 4
  %cmp3 = icmp eq i32 %12, 1
  br i1 %cmp3, label %13, label %14

; <label>:13:                                     ; preds = %11, %9, %7, %5
  br label %16

; <label>:14:                                     ; preds = %11
  call void @__assert_fail(i8* getelementptr inbounds ([80 x i8], [80 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([47 x i8], [47 x i8]* @.str.1, i32 0, i32 0), i32 47, i8* getelementptr inbounds ([40 x i8], [40 x i8]* @__PRETTY_FUNCTION__.is_wall, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %16

; <label>:16:                                     ; preds = %15, %13
  %17 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %18 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %pos_x = getelementptr inbounds %struct.maze, %struct.maze* %18, i32 0, i32 6
  %19 = load i32, i32* %pos_x, align 8
  %20 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %pos_y = getelementptr inbounds %struct.maze, %struct.maze* %20, i32 0, i32 7
  %21 = load i32, i32* %pos_y, align 4
  %call = call i8* @loc(%struct.maze* %17, i32 %19, i32 %21)
  store i8* %call, i8** %position, align 8
  %22 = load i32, i32* %direction.addr, align 4
  %cmp4 = icmp eq i32 %22, 0
  br i1 %cmp4, label %23, label %27

; <label>:23:                                     ; preds = %16
  %24 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %width = getelementptr inbounds %struct.maze, %struct.maze* %24, i32 0, i32 0
  %25 = load i32, i32* %width, align 8
  %mul = mul nsw i32 %25, 2
  %add = add nsw i32 %mul, 2
  %26 = load i8*, i8** %position, align 8
  %idx.ext = sext i32 %add to i64
  %idx.neg = sub i64 0, %idx.ext
  %add.ptr = getelementptr inbounds i8, i8* %26, i64 %idx.neg
  store i8* %add.ptr, i8** %position, align 8
  br label %27

; <label>:27:                                     ; preds = %23, %16
  %28 = load i32, i32* %direction.addr, align 4
  %cmp5 = icmp eq i32 %28, 2
  br i1 %cmp5, label %29, label %33

; <label>:29:                                     ; preds = %27
  %30 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %width6 = getelementptr inbounds %struct.maze, %struct.maze* %30, i32 0, i32 0
  %31 = load i32, i32* %width6, align 8
  %mul7 = mul nsw i32 %31, 2
  %add8 = add nsw i32 %mul7, 2
  %32 = load i8*, i8** %position, align 8
  %idx.ext9 = sext i32 %add8 to i64
  %add.ptr10 = getelementptr inbounds i8, i8* %32, i64 %idx.ext9
  store i8* %add.ptr10, i8** %position, align 8
  br label %33

; <label>:33:                                     ; preds = %29, %27
  %34 = load i32, i32* %direction.addr, align 4
  %cmp11 = icmp eq i32 %34, 3
  br i1 %cmp11, label %35, label %37

; <label>:35:                                     ; preds = %33
  %36 = load i8*, i8** %position, align 8
  %incdec.ptr = getelementptr inbounds i8, i8* %36, i32 -1
  store i8* %incdec.ptr, i8** %position, align 8
  br label %37

; <label>:37:                                     ; preds = %35, %33
  %38 = load i32, i32* %direction.addr, align 4
  %cmp12 = icmp eq i32 %38, 1
  br i1 %cmp12, label %39, label %41

; <label>:39:                                     ; preds = %37
  %40 = load i8*, i8** %position, align 8
  %incdec.ptr13 = getelementptr inbounds i8, i8* %40, i32 1
  store i8* %incdec.ptr13, i8** %position, align 8
  br label %41

; <label>:41:                                     ; preds = %39, %37
  %42 = load i8*, i8** %position, align 8
  %43 = load i8, i8* %42, align 1
  %conv = sext i8 %43 to i32
  %cmp14 = icmp eq i32 %conv, 46
  br i1 %cmp14, label %44, label %45

; <label>:44:                                     ; preds = %41
  store i1 false, i1* %retval, align 1
  br label %54

; <label>:45:                                     ; preds = %41
  %46 = load i8*, i8** %position, align 8
  %47 = load i8, i8* %46, align 1
  %conv16 = sext i8 %47 to i32
  %cmp17 = icmp eq i32 %conv16, 124
  br i1 %cmp17, label %51, label %48

; <label>:48:                                     ; preds = %45
  %49 = load i8*, i8** %position, align 8
  %50 = load i8, i8* %49, align 1
  %conv19 = sext i8 %50 to i32
  %cmp20 = icmp eq i32 %conv19, 45
  br i1 %cmp20, label %51, label %52

; <label>:51:                                     ; preds = %48, %45
  store i1 true, i1* %retval, align 1
  br label %54

; <label>:52:                                     ; preds = %48
  %53 = load %struct.maze*, %struct.maze** %m.addr, align 8
  call void @invalid_maze(%struct.maze* %53)
  store i1 false, i1* %retval, align 1
  br label %54

; <label>:54:                                     ; preds = %52, %51, %44
  %55 = load i1, i1* %retval, align 1
  ret i1 %55
}

; Function Attrs: noreturn nounwind
declare void @__assert_fail(i8*, i8*, i32, i8*) #1

; Function Attrs: nounwind
define internal i8* @loc(%struct.maze* %m, i32 %x, i32 %y) #0 {
  %m.addr = alloca %struct.maze*, align 8
  %x.addr = alloca i32, align 4
  %y.addr = alloca i32, align 4
  store %struct.maze* %m, %struct.maze** %m.addr, align 8
  store i32 %x, i32* %x.addr, align 4
  store i32 %y, i32* %y.addr, align 4
  %1 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %grid = getelementptr inbounds %struct.maze, %struct.maze* %1, i32 0, i32 8
  %2 = load i8*, i8** %grid, align 8
  %3 = load i32, i32* %y.addr, align 4
  %mul = mul nsw i32 2, %3
  %add = add nsw i32 %mul, 1
  %4 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %width = getelementptr inbounds %struct.maze, %struct.maze* %4, i32 0, i32 0
  %5 = load i32, i32* %width, align 8
  %mul1 = mul nsw i32 2, %5
  %add2 = add nsw i32 %mul1, 2
  %mul3 = mul nsw i32 %add, %add2
  %idx.ext = sext i32 %mul3 to i64
  %add.ptr = getelementptr inbounds i8, i8* %2, i64 %idx.ext
  %6 = load i32, i32* %x.addr, align 4
  %mul4 = mul nsw i32 2, %6
  %idx.ext5 = sext i32 %mul4 to i64
  %add.ptr6 = getelementptr inbounds i8, i8* %add.ptr, i64 %idx.ext5
  %add.ptr7 = getelementptr inbounds i8, i8* %add.ptr6, i64 1
  ret i8* %add.ptr7
}

; Function Attrs: nounwind
define internal void @invalid_maze(%struct.maze* %m) #0 {
  %m.addr = alloca %struct.maze*, align 8
  store %struct.maze* %m, %struct.maze** %m.addr, align 8
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @.str.12, i32 0, i32 0))
  %1 = load %struct.maze*, %struct.maze** %m.addr, align 8
  call void @maze_destroy(%struct.maze* %1)
  call void @exit(i32 1) #5
  unreachable
                                                  ; No predecessors!
  ret void
}

declare i32 @printf(i8*, ...) #2

; Function Attrs: nounwind
define internal void @maze_destroy(%struct.maze* %m) #0 {
  %m.addr = alloca %struct.maze*, align 8
  store %struct.maze* %m, %struct.maze** %m.addr, align 8
  %1 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %tobool = icmp ne %struct.maze* %1, null
  br i1 %tobool, label %2, label %11

; <label>:2:                                      ; preds = %0
  %3 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %grid = getelementptr inbounds %struct.maze, %struct.maze* %3, i32 0, i32 8
  %4 = load i8*, i8** %grid, align 8
  %tobool1 = icmp ne i8* %4, null
  br i1 %tobool1, label %5, label %8

; <label>:5:                                      ; preds = %2
  %6 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %grid2 = getelementptr inbounds %struct.maze, %struct.maze* %6, i32 0, i32 8
  %7 = load i8*, i8** %grid2, align 8
  call void @free(i8* %7) #6
  br label %8

; <label>:8:                                      ; preds = %5, %2
  %9 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %10 = bitcast %struct.maze* %9 to i8*
  call void @free(i8* %10) #6
  br label %11

; <label>:11:                                     ; preds = %8, %0
  ret void
}

; Function Attrs: noreturn nounwind
declare void @exit(i32) #1

; Function Attrs: nounwind
declare void @free(i8*) #3

; Function Attrs: nounwind
define void @move(%struct.maze* %m, i32 %direction) #0 {
  %m.addr = alloca %struct.maze*, align 8
  %direction.addr = alloca i32, align 4
  store %struct.maze* %m, %struct.maze** %m.addr, align 8
  store i32 %direction, i32* %direction.addr, align 4
  %1 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %tobool = icmp ne %struct.maze* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([47 x i8], [47 x i8]* @.str.1, i32 0, i32 0), i32 60, i8* getelementptr inbounds ([30 x i8], [30 x i8]* @__PRETTY_FUNCTION__.move, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load i32, i32* %direction.addr, align 4
  %cmp = icmp eq i32 %6, 0
  br i1 %cmp, label %13, label %7

; <label>:7:                                      ; preds = %5
  %8 = load i32, i32* %direction.addr, align 4
  %cmp1 = icmp eq i32 %8, 2
  br i1 %cmp1, label %13, label %9

; <label>:9:                                      ; preds = %7
  %10 = load i32, i32* %direction.addr, align 4
  %cmp2 = icmp eq i32 %10, 3
  br i1 %cmp2, label %13, label %11

; <label>:11:                                     ; preds = %9
  %12 = load i32, i32* %direction.addr, align 4
  %cmp3 = icmp eq i32 %12, 1
  br i1 %cmp3, label %13, label %14

; <label>:13:                                     ; preds = %11, %9, %7, %5
  br label %16

; <label>:14:                                     ; preds = %11
  call void @__assert_fail(i8* getelementptr inbounds ([80 x i8], [80 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([47 x i8], [47 x i8]* @.str.1, i32 0, i32 0), i32 62, i8* getelementptr inbounds ([30 x i8], [30 x i8]* @__PRETTY_FUNCTION__.move, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %16

; <label>:16:                                     ; preds = %15, %13
  %17 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %18 = load i32, i32* %direction.addr, align 4
  %call = call zeroext i1 @is_wall(%struct.maze* %17, i32 %18)
  br i1 %call, label %19, label %20

; <label>:19:                                     ; preds = %16
  %call4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @.str.3, i32 0, i32 0))
  call void @exit(i32 1) #5
  unreachable

; <label>:20:                                     ; preds = %16
  %21 = load i32, i32* %direction.addr, align 4
  %cmp5 = icmp eq i32 %21, 0
  br i1 %cmp5, label %22, label %25

; <label>:22:                                     ; preds = %20
  %call6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.4, i32 0, i32 0))
  %23 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %pos_y = getelementptr inbounds %struct.maze, %struct.maze* %23, i32 0, i32 7
  %24 = load i32, i32* %pos_y, align 4
  %sub = sub nsw i32 %24, 1
  store i32 %sub, i32* %pos_y, align 4
  br label %25

; <label>:25:                                     ; preds = %22, %20
  %26 = load i32, i32* %direction.addr, align 4
  %cmp7 = icmp eq i32 %26, 2
  br i1 %cmp7, label %27, label %30

; <label>:27:                                     ; preds = %25
  %call8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.5, i32 0, i32 0))
  %28 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %pos_y9 = getelementptr inbounds %struct.maze, %struct.maze* %28, i32 0, i32 7
  %29 = load i32, i32* %pos_y9, align 4
  %add = add nsw i32 %29, 1
  store i32 %add, i32* %pos_y9, align 4
  br label %30

; <label>:30:                                     ; preds = %27, %25
  %31 = load i32, i32* %direction.addr, align 4
  %cmp10 = icmp eq i32 %31, 3
  br i1 %cmp10, label %32, label %35

; <label>:32:                                     ; preds = %30
  %call11 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.6, i32 0, i32 0))
  %33 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %pos_x = getelementptr inbounds %struct.maze, %struct.maze* %33, i32 0, i32 6
  %34 = load i32, i32* %pos_x, align 8
  %sub12 = sub nsw i32 %34, 1
  store i32 %sub12, i32* %pos_x, align 8
  br label %35

; <label>:35:                                     ; preds = %32, %30
  %36 = load i32, i32* %direction.addr, align 4
  %cmp13 = icmp eq i32 %36, 1
  br i1 %cmp13, label %37, label %40

; <label>:37:                                     ; preds = %35
  %call14 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.7, i32 0, i32 0))
  %38 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %pos_x15 = getelementptr inbounds %struct.maze, %struct.maze* %38, i32 0, i32 6
  %39 = load i32, i32* %pos_x15, align 8
  %add16 = add nsw i32 %39, 1
  store i32 %add16, i32* %pos_x15, align 8
  br label %40

; <label>:40:                                     ; preds = %37, %35
  %41 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %pos_y17 = getelementptr inbounds %struct.maze, %struct.maze* %41, i32 0, i32 7
  %42 = load i32, i32* %pos_y17, align 4
  %cmp18 = icmp slt i32 %42, 0
  br i1 %cmp18, label %56, label %43

; <label>:43:                                     ; preds = %40
  %44 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %pos_y19 = getelementptr inbounds %struct.maze, %struct.maze* %44, i32 0, i32 7
  %45 = load i32, i32* %pos_y19, align 4
  %46 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %height = getelementptr inbounds %struct.maze, %struct.maze* %46, i32 0, i32 1
  %47 = load i32, i32* %height, align 4
  %cmp20 = icmp sge i32 %45, %47
  br i1 %cmp20, label %56, label %48

; <label>:48:                                     ; preds = %43
  %49 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %pos_x21 = getelementptr inbounds %struct.maze, %struct.maze* %49, i32 0, i32 6
  %50 = load i32, i32* %pos_x21, align 8
  %cmp22 = icmp slt i32 %50, 0
  br i1 %cmp22, label %56, label %51

; <label>:51:                                     ; preds = %48
  %52 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %pos_x23 = getelementptr inbounds %struct.maze, %struct.maze* %52, i32 0, i32 6
  %53 = load i32, i32* %pos_x23, align 8
  %54 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %width = getelementptr inbounds %struct.maze, %struct.maze* %54, i32 0, i32 0
  %55 = load i32, i32* %width, align 8
  %cmp24 = icmp sge i32 %53, %55
  br i1 %cmp24, label %56, label %57

; <label>:56:                                     ; preds = %51, %48, %43, %40
  %call25 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([35 x i8], [35 x i8]* @.str.8, i32 0, i32 0))
  call void @exit(i32 1) #5
  unreachable

; <label>:57:                                     ; preds = %51
  %58 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %pos_x26 = getelementptr inbounds %struct.maze, %struct.maze* %58, i32 0, i32 6
  %59 = load i32, i32* %pos_x26, align 8
  %60 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %exit_x = getelementptr inbounds %struct.maze, %struct.maze* %60, i32 0, i32 4
  %61 = load i32, i32* %exit_x, align 8
  %cmp27 = icmp eq i32 %59, %61
  br i1 %cmp27, label %62, label %68

; <label>:62:                                     ; preds = %57
  %63 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %pos_y28 = getelementptr inbounds %struct.maze, %struct.maze* %63, i32 0, i32 7
  %64 = load i32, i32* %pos_y28, align 4
  %65 = load %struct.maze*, %struct.maze** %m.addr, align 8
  %exit_y = getelementptr inbounds %struct.maze, %struct.maze* %65, i32 0, i32 5
  %66 = load i32, i32* %exit_y, align 4
  %cmp29 = icmp eq i32 %64, %66
  br i1 %cmp29, label %67, label %68

; <label>:67:                                     ; preds = %62
  %call30 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.9, i32 0, i32 0))
  call void @exit(i32 0) #5
  unreachable

; <label>:68:                                     ; preds = %62, %57
  ret void
}

; Function Attrs: nounwind
define %struct.maze* @read_maze() #0 {
  %m = alloca %struct.maze*, align 8
  %h = alloca i32, align 4
  %w = alloca i32, align 4
  %y = alloca i32, align 4
  %y31 = alloca i32, align 4
  %x = alloca i32, align 4
  %c = alloca i8, align 1
  %y66 = alloca i32, align 4
  %x70 = alloca i32, align 4
  %call = call noalias i8* @malloc(i64 40) #6
  %1 = bitcast i8* %call to %struct.maze*
  store %struct.maze* %1, %struct.maze** %m, align 8
  %2 = load %struct.maze*, %struct.maze** %m, align 8
  %grid = getelementptr inbounds %struct.maze, %struct.maze* %2, i32 0, i32 8
  store i8* null, i8** %grid, align 8
  %3 = load %struct.maze*, %struct.maze** %m, align 8
  %width = getelementptr inbounds %struct.maze, %struct.maze* %3, i32 0, i32 0
  %call1 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.10, i32 0, i32 0), i32* %width)
  %cmp = icmp ne i32 %call1, 1
  br i1 %cmp, label %4, label %6

; <label>:4:                                      ; preds = %0
  %5 = load %struct.maze*, %struct.maze** %m, align 8
  call void @invalid_maze(%struct.maze* %5)
  br label %6

; <label>:6:                                      ; preds = %4, %0
  %7 = load %struct.maze*, %struct.maze** %m, align 8
  %height = getelementptr inbounds %struct.maze, %struct.maze* %7, i32 0, i32 1
  %call2 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.10, i32 0, i32 0), i32* %height)
  %cmp3 = icmp ne i32 %call2, 1
  br i1 %cmp3, label %8, label %10

; <label>:8:                                      ; preds = %6
  %9 = load %struct.maze*, %struct.maze** %m, align 8
  call void @invalid_maze(%struct.maze* %9)
  br label %10

; <label>:10:                                     ; preds = %8, %6
  %11 = load %struct.maze*, %struct.maze** %m, align 8
  %width4 = getelementptr inbounds %struct.maze, %struct.maze* %11, i32 0, i32 0
  %12 = load i32, i32* %width4, align 8
  %cmp5 = icmp sle i32 %12, 1
  br i1 %cmp5, label %13, label %15

; <label>:13:                                     ; preds = %10
  %14 = load %struct.maze*, %struct.maze** %m, align 8
  call void @invalid_maze(%struct.maze* %14)
  br label %15

; <label>:15:                                     ; preds = %13, %10
  %16 = load %struct.maze*, %struct.maze** %m, align 8
  %height6 = getelementptr inbounds %struct.maze, %struct.maze* %16, i32 0, i32 1
  %17 = load i32, i32* %height6, align 4
  %cmp7 = icmp sle i32 %17, 1
  br i1 %cmp7, label %18, label %20

; <label>:18:                                     ; preds = %15
  %19 = load %struct.maze*, %struct.maze** %m, align 8
  call void @invalid_maze(%struct.maze* %19)
  br label %20

; <label>:20:                                     ; preds = %18, %15
  %21 = load %struct.maze*, %struct.maze** %m, align 8
  %height8 = getelementptr inbounds %struct.maze, %struct.maze* %21, i32 0, i32 1
  %22 = load i32, i32* %height8, align 4
  %mul = mul nsw i32 2, %22
  %add = add nsw i32 %mul, 1
  store i32 %add, i32* %h, align 4
  %23 = load %struct.maze*, %struct.maze** %m, align 8
  %width9 = getelementptr inbounds %struct.maze, %struct.maze* %23, i32 0, i32 0
  %24 = load i32, i32* %width9, align 8
  %mul10 = mul nsw i32 2, %24
  %add11 = add nsw i32 %mul10, 1
  store i32 %add11, i32* %w, align 4
  %25 = load i32, i32* %h, align 4
  %conv = sext i32 %25 to i64
  %mul12 = mul i64 1, %conv
  %26 = load i32, i32* %w, align 4
  %add13 = add nsw i32 %26, 1
  %conv14 = sext i32 %add13 to i64
  %mul15 = mul i64 %mul12, %conv14
  %call16 = call noalias i8* @malloc(i64 %mul15) #6
  %27 = load %struct.maze*, %struct.maze** %m, align 8
  %grid17 = getelementptr inbounds %struct.maze, %struct.maze* %27, i32 0, i32 8
  store i8* %call16, i8** %grid17, align 8
  store i32 0, i32* %y, align 4
  br label %28

; <label>:28:                                     ; preds = %43, %20
  %29 = load i32, i32* %y, align 4
  %30 = load i32, i32* %h, align 4
  %cmp18 = icmp slt i32 %29, %30
  br i1 %cmp18, label %31, label %45

; <label>:31:                                     ; preds = %28
  %call20 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.11, i32 0, i32 0), i8* getelementptr inbounds ([1049600 x i8], [1049600 x i8]* @bigbuffer, i32 0, i32 0))
  %cmp21 = icmp ne i32 %call20, 1
  br i1 %cmp21, label %32, label %34

; <label>:32:                                     ; preds = %31
  %33 = load %struct.maze*, %struct.maze** %m, align 8
  call void @invalid_maze(%struct.maze* %33)
  br label %34

; <label>:34:                                     ; preds = %32, %31
  %call23 = call i64 @strlen(i8* getelementptr inbounds ([1049600 x i8], [1049600 x i8]* @bigbuffer, i32 0, i32 0)) #7
  %35 = load i32, i32* %w, align 4
  %conv24 = sext i32 %35 to i64
  %cmp25 = icmp ne i64 %call23, %conv24
  br i1 %cmp25, label %36, label %38

; <label>:36:                                     ; preds = %34
  %37 = load %struct.maze*, %struct.maze** %m, align 8
  call void @invalid_maze(%struct.maze* %37)
  br label %38

; <label>:38:                                     ; preds = %36, %34
  %39 = load %struct.maze*, %struct.maze** %m, align 8
  %grid27 = getelementptr inbounds %struct.maze, %struct.maze* %39, i32 0, i32 8
  %40 = load i8*, i8** %grid27, align 8
  %41 = load i32, i32* %y, align 4
  %42 = load i32, i32* %w, align 4
  %add28 = add nsw i32 %42, 1
  %mul29 = mul nsw i32 %41, %add28
  %idx.ext = sext i32 %mul29 to i64
  %add.ptr = getelementptr inbounds i8, i8* %40, i64 %idx.ext
  %call30 = call i8* @strcpy(i8* %add.ptr, i8* getelementptr inbounds ([1049600 x i8], [1049600 x i8]* @bigbuffer, i32 0, i32 0)) #6
  br label %43

; <label>:43:                                     ; preds = %38
  %44 = load i32, i32* %y, align 4
  %inc = add nsw i32 %44, 1
  store i32 %inc, i32* %y, align 4
  br label %28

; <label>:45:                                     ; preds = %28
  %46 = load %struct.maze*, %struct.maze** %m, align 8
  %exit_y = getelementptr inbounds %struct.maze, %struct.maze* %46, i32 0, i32 5
  store i32 -1, i32* %exit_y, align 4
  %47 = load %struct.maze*, %struct.maze** %m, align 8
  %exit_x = getelementptr inbounds %struct.maze, %struct.maze* %47, i32 0, i32 4
  store i32 -1, i32* %exit_x, align 8
  %48 = load %struct.maze*, %struct.maze** %m, align 8
  %start_y = getelementptr inbounds %struct.maze, %struct.maze* %48, i32 0, i32 3
  store i32 -1, i32* %start_y, align 4
  %49 = load %struct.maze*, %struct.maze** %m, align 8
  %start_x = getelementptr inbounds %struct.maze, %struct.maze* %49, i32 0, i32 2
  store i32 -1, i32* %start_x, align 8
  store i32 0, i32* %y31, align 4
  br label %50

; <label>:50:                                     ; preds = %87, %45
  %51 = load i32, i32* %y31, align 4
  %52 = load %struct.maze*, %struct.maze** %m, align 8
  %height32 = getelementptr inbounds %struct.maze, %struct.maze* %52, i32 0, i32 1
  %53 = load i32, i32* %height32, align 4
  %cmp33 = icmp slt i32 %51, %53
  br i1 %cmp33, label %54, label %89

; <label>:54:                                     ; preds = %50
  store i32 0, i32* %x, align 4
  br label %55

; <label>:55:                                     ; preds = %84, %54
  %56 = load i32, i32* %x, align 4
  %57 = load %struct.maze*, %struct.maze** %m, align 8
  %width35 = getelementptr inbounds %struct.maze, %struct.maze* %57, i32 0, i32 0
  %58 = load i32, i32* %width35, align 8
  %cmp36 = icmp slt i32 %56, %58
  br i1 %cmp36, label %59, label %86

; <label>:59:                                     ; preds = %55
  %60 = load %struct.maze*, %struct.maze** %m, align 8
  %61 = load i32, i32* %x, align 4
  %62 = load i32, i32* %y31, align 4
  %call38 = call i8* @loc(%struct.maze* %60, i32 %61, i32 %62)
  %63 = load i8, i8* %call38, align 1
  store i8 %63, i8* %c, align 1
  %64 = load i8, i8* %c, align 1
  %conv39 = sext i8 %64 to i32
  %cmp40 = icmp eq i32 %conv39, 83
  br i1 %cmp40, label %65, label %70

; <label>:65:                                     ; preds = %59
  %66 = load i32, i32* %x, align 4
  %67 = load %struct.maze*, %struct.maze** %m, align 8
  %start_x42 = getelementptr inbounds %struct.maze, %struct.maze* %67, i32 0, i32 2
  store i32 %66, i32* %start_x42, align 8
  %68 = load i32, i32* %y31, align 4
  %69 = load %struct.maze*, %struct.maze** %m, align 8
  %start_y43 = getelementptr inbounds %struct.maze, %struct.maze* %69, i32 0, i32 3
  store i32 %68, i32* %start_y43, align 4
  br label %83

; <label>:70:                                     ; preds = %59
  %71 = load i8, i8* %c, align 1
  %conv44 = sext i8 %71 to i32
  %cmp45 = icmp eq i32 %conv44, 69
  br i1 %cmp45, label %72, label %77

; <label>:72:                                     ; preds = %70
  %73 = load i32, i32* %x, align 4
  %74 = load %struct.maze*, %struct.maze** %m, align 8
  %exit_x47 = getelementptr inbounds %struct.maze, %struct.maze* %74, i32 0, i32 4
  store i32 %73, i32* %exit_x47, align 8
  %75 = load i32, i32* %y31, align 4
  %76 = load %struct.maze*, %struct.maze** %m, align 8
  %exit_y48 = getelementptr inbounds %struct.maze, %struct.maze* %76, i32 0, i32 5
  store i32 %75, i32* %exit_y48, align 4
  br label %82

; <label>:77:                                     ; preds = %70
  %78 = load i8, i8* %c, align 1
  %conv49 = sext i8 %78 to i32
  %cmp50 = icmp ne i32 %conv49, 46
  br i1 %cmp50, label %79, label %81

; <label>:79:                                     ; preds = %77
  %80 = load %struct.maze*, %struct.maze** %m, align 8
  call void @invalid_maze(%struct.maze* %80)
  br label %81

; <label>:81:                                     ; preds = %79, %77
  br label %82

; <label>:82:                                     ; preds = %81, %72
  br label %83

; <label>:83:                                     ; preds = %82, %65
  br label %84

; <label>:84:                                     ; preds = %83
  %85 = load i32, i32* %x, align 4
  %inc52 = add nsw i32 %85, 1
  store i32 %inc52, i32* %x, align 4
  br label %55

; <label>:86:                                     ; preds = %55
  br label %87

; <label>:87:                                     ; preds = %86
  %88 = load i32, i32* %y31, align 4
  %inc53 = add nsw i32 %88, 1
  store i32 %inc53, i32* %y31, align 4
  br label %50

; <label>:89:                                     ; preds = %50
  %90 = load %struct.maze*, %struct.maze** %m, align 8
  %start_x54 = getelementptr inbounds %struct.maze, %struct.maze* %90, i32 0, i32 2
  %91 = load i32, i32* %start_x54, align 8
  %cmp55 = icmp eq i32 %91, -1
  br i1 %cmp55, label %101, label %92

; <label>:92:                                     ; preds = %89
  %93 = load %struct.maze*, %struct.maze** %m, align 8
  %start_y57 = getelementptr inbounds %struct.maze, %struct.maze* %93, i32 0, i32 3
  %94 = load i32, i32* %start_y57, align 4
  %cmp58 = icmp eq i32 %94, -1
  br i1 %cmp58, label %101, label %95

; <label>:95:                                     ; preds = %92
  %96 = load %struct.maze*, %struct.maze** %m, align 8
  %exit_x60 = getelementptr inbounds %struct.maze, %struct.maze* %96, i32 0, i32 4
  %97 = load i32, i32* %exit_x60, align 8
  %cmp61 = icmp eq i32 %97, -1
  br i1 %cmp61, label %101, label %98

; <label>:98:                                     ; preds = %95
  %99 = load %struct.maze*, %struct.maze** %m, align 8
  %exit_y63 = getelementptr inbounds %struct.maze, %struct.maze* %99, i32 0, i32 5
  %100 = load i32, i32* %exit_y63, align 4
  %cmp64 = icmp eq i32 %100, -1
  br i1 %cmp64, label %101, label %103

; <label>:101:                                    ; preds = %98, %95, %92, %89
  %102 = load %struct.maze*, %struct.maze** %m, align 8
  call void @invalid_maze(%struct.maze* %102)
  br label %103

; <label>:103:                                    ; preds = %101, %98
  store i32 0, i32* %y66, align 4
  br label %104

; <label>:104:                                    ; preds = %125, %103
  %105 = load i32, i32* %y66, align 4
  %106 = load %struct.maze*, %struct.maze** %m, align 8
  %height67 = getelementptr inbounds %struct.maze, %struct.maze* %106, i32 0, i32 1
  %107 = load i32, i32* %height67, align 4
  %cmp68 = icmp slt i32 %105, %107
  br i1 %cmp68, label %108, label %127

; <label>:108:                                    ; preds = %104
  store i32 0, i32* %x70, align 4
  br label %109

; <label>:109:                                    ; preds = %122, %108
  %110 = load i32, i32* %x70, align 4
  %111 = load %struct.maze*, %struct.maze** %m, align 8
  %width71 = getelementptr inbounds %struct.maze, %struct.maze* %111, i32 0, i32 0
  %112 = load i32, i32* %width71, align 8
  %cmp72 = icmp slt i32 %110, %112
  br i1 %cmp72, label %113, label %124

; <label>:113:                                    ; preds = %109
  %114 = load i32, i32* %x70, align 4
  %115 = load %struct.maze*, %struct.maze** %m, align 8
  %pos_x = getelementptr inbounds %struct.maze, %struct.maze* %115, i32 0, i32 6
  store i32 %114, i32* %pos_x, align 8
  %116 = load i32, i32* %y66, align 4
  %117 = load %struct.maze*, %struct.maze** %m, align 8
  %pos_y = getelementptr inbounds %struct.maze, %struct.maze* %117, i32 0, i32 7
  store i32 %116, i32* %pos_y, align 4
  %118 = load %struct.maze*, %struct.maze** %m, align 8
  %call74 = call zeroext i1 @is_wall(%struct.maze* %118, i32 0)
  %119 = load %struct.maze*, %struct.maze** %m, align 8
  %call75 = call zeroext i1 @is_wall(%struct.maze* %119, i32 2)
  %120 = load %struct.maze*, %struct.maze** %m, align 8
  %call76 = call zeroext i1 @is_wall(%struct.maze* %120, i32 3)
  %121 = load %struct.maze*, %struct.maze** %m, align 8
  %call77 = call zeroext i1 @is_wall(%struct.maze* %121, i32 1)
  br label %122

; <label>:122:                                    ; preds = %113
  %123 = load i32, i32* %x70, align 4
  %inc78 = add nsw i32 %123, 1
  store i32 %inc78, i32* %x70, align 4
  br label %109

; <label>:124:                                    ; preds = %109
  br label %125

; <label>:125:                                    ; preds = %124
  %126 = load i32, i32* %y66, align 4
  %inc79 = add nsw i32 %126, 1
  store i32 %inc79, i32* %y66, align 4
  br label %104

; <label>:127:                                    ; preds = %104
  %128 = load %struct.maze*, %struct.maze** %m, align 8
  %start_x80 = getelementptr inbounds %struct.maze, %struct.maze* %128, i32 0, i32 2
  %129 = load i32, i32* %start_x80, align 8
  %130 = load %struct.maze*, %struct.maze** %m, align 8
  %pos_x81 = getelementptr inbounds %struct.maze, %struct.maze* %130, i32 0, i32 6
  store i32 %129, i32* %pos_x81, align 8
  %131 = load %struct.maze*, %struct.maze** %m, align 8
  %start_y82 = getelementptr inbounds %struct.maze, %struct.maze* %131, i32 0, i32 3
  %132 = load i32, i32* %start_y82, align 4
  %133 = load %struct.maze*, %struct.maze** %m, align 8
  %pos_y83 = getelementptr inbounds %struct.maze, %struct.maze* %133, i32 0, i32 7
  store i32 %132, i32* %pos_y83, align 4
  %134 = load %struct.maze*, %struct.maze** %m, align 8
  ret %struct.maze* %134
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #3

declare i32 @__isoc99_scanf(i8*, ...) #2

; Function Attrs: nounwind readonly
declare i64 @strlen(i8*) #4

; Function Attrs: nounwind
declare i8* @strcpy(i8*, i8*) #3

attributes #0 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { noreturn nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind readonly "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { noreturn nounwind }
attributes #6 = { nounwind }
attributes #7 = { nounwind readonly }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.9.1 "}
