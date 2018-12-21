; ModuleID = 'seashell-compiler-output'
source_filename = "seashell-compiler-output"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [15 x i8] c"tolerance >= 0\00", align 1
@.str.1 = private unnamed_addr constant [56 x i8] c"/u1/dtompkins/.seashell/projects/_A7/common/tolerance.c\00", align 1
@__PRETTY_FUNCTION__.within_tolerance = private unnamed_addr constant [65 x i8] c"_Bool within_tolerance(const double, const double, const double)\00", align 1

; Function Attrs: nounwind
define zeroext i1 @within_tolerance(double %a, double %b, double %tolerance) #0 {
  %retval = alloca i1, align 1
  %a.addr = alloca double, align 8
  %b.addr = alloca double, align 8
  %tolerance.addr = alloca double, align 8
  store double %a, double* %a.addr, align 8
  store double %b, double* %b.addr, align 8
  store double %tolerance, double* %tolerance.addr, align 8
  %1 = load double, double* %tolerance.addr, align 8
  %cmp = fcmp oge double %1, 0.000000e+00
  br i1 %cmp, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([56 x i8], [56 x i8]* @.str.1, i32 0, i32 0), i32 7, i8* getelementptr inbounds ([65 x i8], [65 x i8]* @__PRETTY_FUNCTION__.within_tolerance, i32 0, i32 0)) #2
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load double, double* %a.addr, align 8
  %7 = load double, double* %b.addr, align 8
  %cmp1 = fcmp olt double %6, %7
  br i1 %cmp1, label %8, label %12

; <label>:8:                                      ; preds = %5
  %9 = load double, double* %b.addr, align 8
  %10 = load double, double* %a.addr, align 8
  %sub = fsub double %9, %10
  %11 = load double, double* %tolerance.addr, align 8
  %cmp2 = fcmp ole double %sub, %11
  store i1 %cmp2, i1* %retval, align 1
  br label %16

; <label>:12:                                     ; preds = %5
  %13 = load double, double* %a.addr, align 8
  %14 = load double, double* %b.addr, align 8
  %sub3 = fsub double %13, %14
  %15 = load double, double* %tolerance.addr, align 8
  %cmp4 = fcmp ole double %sub3, %15
  store i1 %cmp4, i1* %retval, align 1
  br label %16

; <label>:16:                                     ; preds = %12, %8
  %17 = load i1, i1* %retval, align 1
  ret i1 %17
}

; Function Attrs: noreturn nounwind
declare void @__assert_fail(i8*, i8*, i32, i8*) #1

attributes #0 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { noreturn nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noreturn nounwind }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.9.1 "}
