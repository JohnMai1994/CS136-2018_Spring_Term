; ModuleID = 'seashell-compiler-output'
source_filename = "seashell-compiler-output"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: nounwind
define void @merge_sort(i32* %a, i32 %len) #0 {
  %a.addr = alloca i32*, align 8
  %len.addr = alloca i32, align 4
  %llen = alloca i32, align 4
  %rlen = alloca i32, align 4
  %left = alloca i32*, align 8
  %right = alloca i32*, align 8
  %i = alloca i32, align 4
  %i8 = alloca i32, align 4
  store i32* %a, i32** %a.addr, align 8
  store i32 %len, i32* %len.addr, align 4
  %1 = load i32, i32* %len.addr, align 4
  %cmp = icmp sle i32 %1, 1
  br i1 %cmp, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %49

; <label>:3:                                      ; preds = %0
  %4 = load i32, i32* %len.addr, align 4
  %div = sdiv i32 %4, 2
  store i32 %div, i32* %llen, align 4
  %5 = load i32, i32* %len.addr, align 4
  %6 = load i32, i32* %llen, align 4
  %sub = sub nsw i32 %5, %6
  store i32 %sub, i32* %rlen, align 4
  %7 = load i32, i32* %llen, align 4
  %conv = sext i32 %7 to i64
  %mul = mul i64 %conv, 4
  %call = call noalias i8* @malloc(i64 %mul) #2
  %8 = bitcast i8* %call to i32*
  store i32* %8, i32** %left, align 8
  %9 = load i32, i32* %rlen, align 4
  %conv1 = sext i32 %9 to i64
  %mul2 = mul i64 %conv1, 4
  %call3 = call noalias i8* @malloc(i64 %mul2) #2
  %10 = bitcast i8* %call3 to i32*
  store i32* %10, i32** %right, align 8
  store i32 0, i32* %i, align 4
  br label %11

; <label>:11:                                     ; preds = %20, %3
  %12 = load i32, i32* %i, align 4
  %13 = load i32, i32* %llen, align 4
  %cmp4 = icmp slt i32 %12, %13
  br i1 %cmp4, label %14, label %22

; <label>:14:                                     ; preds = %11
  %15 = load i32, i32* %i, align 4
  %idxprom = sext i32 %15 to i64
  %16 = load i32*, i32** %a.addr, align 8
  %arrayidx = getelementptr inbounds i32, i32* %16, i64 %idxprom
  %17 = load i32, i32* %arrayidx, align 4
  %18 = load i32, i32* %i, align 4
  %idxprom6 = sext i32 %18 to i64
  %19 = load i32*, i32** %left, align 8
  %arrayidx7 = getelementptr inbounds i32, i32* %19, i64 %idxprom6
  store i32 %17, i32* %arrayidx7, align 4
  br label %20

; <label>:20:                                     ; preds = %14
  %21 = load i32, i32* %i, align 4
  %inc = add nsw i32 %21, 1
  store i32 %inc, i32* %i, align 4
  br label %11

; <label>:22:                                     ; preds = %11
  store i32 0, i32* %i8, align 4
  br label %23

; <label>:23:                                     ; preds = %33, %22
  %24 = load i32, i32* %i8, align 4
  %25 = load i32, i32* %rlen, align 4
  %cmp9 = icmp slt i32 %24, %25
  br i1 %cmp9, label %26, label %35

; <label>:26:                                     ; preds = %23
  %27 = load i32, i32* %i8, align 4
  %28 = load i32, i32* %llen, align 4
  %add = add nsw i32 %27, %28
  %idxprom11 = sext i32 %add to i64
  %29 = load i32*, i32** %a.addr, align 8
  %arrayidx12 = getelementptr inbounds i32, i32* %29, i64 %idxprom11
  %30 = load i32, i32* %arrayidx12, align 4
  %31 = load i32, i32* %i8, align 4
  %idxprom13 = sext i32 %31 to i64
  %32 = load i32*, i32** %right, align 8
  %arrayidx14 = getelementptr inbounds i32, i32* %32, i64 %idxprom13
  store i32 %30, i32* %arrayidx14, align 4
  br label %33

; <label>:33:                                     ; preds = %26
  %34 = load i32, i32* %i8, align 4
  %inc15 = add nsw i32 %34, 1
  store i32 %inc15, i32* %i8, align 4
  br label %23

; <label>:35:                                     ; preds = %23
  %36 = load i32*, i32** %left, align 8
  %37 = load i32, i32* %llen, align 4
  call void @merge_sort(i32* %36, i32 %37)
  %38 = load i32*, i32** %right, align 8
  %39 = load i32, i32* %rlen, align 4
  call void @merge_sort(i32* %38, i32 %39)
  %40 = load i32*, i32** %a.addr, align 8
  %41 = load i32*, i32** %left, align 8
  %42 = load i32, i32* %llen, align 4
  %43 = load i32*, i32** %right, align 8
  %44 = load i32, i32* %rlen, align 4
  call void @merge(i32* %40, i32* %41, i32 %42, i32* %43, i32 %44)
  %45 = load i32*, i32** %left, align 8
  %46 = bitcast i32* %45 to i8*
  call void @free(i8* %46) #2
  %47 = load i32*, i32** %right, align 8
  %48 = bitcast i32* %47 to i8*
  call void @free(i8* %48) #2
  br label %49

; <label>:49:                                     ; preds = %35, %2
  ret void
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

; Function Attrs: nounwind
define internal void @merge(i32* %dest, i32* %src1, i32 %len1, i32* %src2, i32 %len2) #0 {
  %dest.addr = alloca i32*, align 8
  %src1.addr = alloca i32*, align 8
  %len1.addr = alloca i32, align 4
  %src2.addr = alloca i32*, align 8
  %len2.addr = alloca i32, align 4
  %pos1 = alloca i32, align 4
  %pos2 = alloca i32, align 4
  %i = alloca i32, align 4
  store i32* %dest, i32** %dest.addr, align 8
  store i32* %src1, i32** %src1.addr, align 8
  store i32 %len1, i32* %len1.addr, align 4
  store i32* %src2, i32** %src2.addr, align 8
  store i32 %len2, i32* %len2.addr, align 4
  store i32 0, i32* %pos1, align 4
  store i32 0, i32* %pos2, align 4
  store i32 0, i32* %i, align 4
  br label %1

; <label>:1:                                      ; preds = %33, %0
  %2 = load i32, i32* %i, align 4
  %3 = load i32, i32* %len1.addr, align 4
  %4 = load i32, i32* %len2.addr, align 4
  %add = add nsw i32 %3, %4
  %cmp = icmp slt i32 %2, %add
  br i1 %cmp, label %5, label %35

; <label>:5:                                      ; preds = %1
  %6 = load i32, i32* %pos1, align 4
  %7 = load i32, i32* %len1.addr, align 4
  %cmp1 = icmp eq i32 %6, %7
  br i1 %cmp1, label %18, label %8

; <label>:8:                                      ; preds = %5
  %9 = load i32, i32* %pos2, align 4
  %10 = load i32, i32* %len2.addr, align 4
  %cmp2 = icmp slt i32 %9, %10
  br i1 %cmp2, label %11, label %25

; <label>:11:                                     ; preds = %8
  %12 = load i32, i32* %pos2, align 4
  %idxprom = sext i32 %12 to i64
  %13 = load i32*, i32** %src2.addr, align 8
  %arrayidx = getelementptr inbounds i32, i32* %13, i64 %idxprom
  %14 = load i32, i32* %arrayidx, align 4
  %15 = load i32, i32* %pos1, align 4
  %idxprom3 = sext i32 %15 to i64
  %16 = load i32*, i32** %src1.addr, align 8
  %arrayidx4 = getelementptr inbounds i32, i32* %16, i64 %idxprom3
  %17 = load i32, i32* %arrayidx4, align 4
  %cmp5 = icmp slt i32 %14, %17
  br i1 %cmp5, label %18, label %25

; <label>:18:                                     ; preds = %11, %5
  %19 = load i32, i32* %pos2, align 4
  %idxprom6 = sext i32 %19 to i64
  %20 = load i32*, i32** %src2.addr, align 8
  %arrayidx7 = getelementptr inbounds i32, i32* %20, i64 %idxprom6
  %21 = load i32, i32* %arrayidx7, align 4
  %22 = load i32, i32* %i, align 4
  %idxprom8 = sext i32 %22 to i64
  %23 = load i32*, i32** %dest.addr, align 8
  %arrayidx9 = getelementptr inbounds i32, i32* %23, i64 %idxprom8
  store i32 %21, i32* %arrayidx9, align 4
  %24 = load i32, i32* %pos2, align 4
  %inc = add nsw i32 %24, 1
  store i32 %inc, i32* %pos2, align 4
  br label %32

; <label>:25:                                     ; preds = %11, %8
  %26 = load i32, i32* %pos1, align 4
  %idxprom10 = sext i32 %26 to i64
  %27 = load i32*, i32** %src1.addr, align 8
  %arrayidx11 = getelementptr inbounds i32, i32* %27, i64 %idxprom10
  %28 = load i32, i32* %arrayidx11, align 4
  %29 = load i32, i32* %i, align 4
  %idxprom12 = sext i32 %29 to i64
  %30 = load i32*, i32** %dest.addr, align 8
  %arrayidx13 = getelementptr inbounds i32, i32* %30, i64 %idxprom12
  store i32 %28, i32* %arrayidx13, align 4
  %31 = load i32, i32* %pos1, align 4
  %inc14 = add nsw i32 %31, 1
  store i32 %inc14, i32* %pos1, align 4
  br label %32

; <label>:32:                                     ; preds = %25, %18
  br label %33

; <label>:33:                                     ; preds = %32
  %34 = load i32, i32* %i, align 4
  %inc15 = add nsw i32 %34, 1
  store i32 %inc15, i32* %i, align 4
  br label %1

; <label>:35:                                     ; preds = %1
  ret void
}

; Function Attrs: nounwind
declare void @free(i8*) #1

attributes #0 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.9.1 "}
