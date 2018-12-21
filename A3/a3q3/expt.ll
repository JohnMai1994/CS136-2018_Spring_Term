; ModuleID = 'seashell-compiler-output'
source_filename = "seashell-compiler-output"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@a1 = internal global [17 x double] [double 1.000000e+00, double 0x3FEEA4AFA2A490DA, double 0x3FED5818DCFBA487, double 0x3FEC199BDD85529C, double 0x3FEAE89F995AD3AD, double 0x3FE9C49182A3F090, double 0x3FE8ACE5422AA0DB, double 0x3FE7A11473EB0187, double 0x3FE6A09E667F3BCD, double 0x3FE5AB07DD485429, double 0x3FE4BFDAD5362A27, double 0x3FE3DEA64C123422, double 0x3FE306FE0A31B715, double 0x3FE2387A6E756238, double 0x3FE172B83C7D517B, double 0x3FE0B5586CF9890F, double 5.000000e-01], align 16
@a2 = internal global [8 x double] [double 0x3C463DCE86400000, double 0x3C31065895000000, double 0xBC3C1DCA7C800000, double 0xBC5055DFB8100000, double 0xBC4CDB3FABA00000, double 0xBC5497DBB8400000, double 0x3C4B07EB6C800000, double 0x3C34C5C95B800000], align 16
@p4 = internal global double 0x3F3C78FDDB4AFC28, align 8
@p3 = internal global double 0x3F6249242E278DAC, align 8
@p2 = internal global double 0x3F899999999E080E, align 8
@p1 = internal global double 0x3FB555555555554D, align 8
@k = internal global double 0x3FDC551D94AE0BF8, align 8
@q7 = internal global double 0x3EEF4EDDE392CC80, align 8
@q6 = internal global double 0x3F242F7AE0384C74, align 8
@q5 = internal global double 0x3F55D87E18D7CD9F, align 8
@q4 = internal global double 0x3F83B2AB6E131D98, align 8
@q3 = internal global double 0x3FAC6B08D703026D, align 8
@q2 = internal global double 0x3FCEBFBDFF82C4CE, align 8
@q1 = internal global double 0x3FE62E42FEFA39EF, align 8

; Function Attrs: nounwind
define double @expt2(double %x, double %y) #0 {
  %retval = alloca double, align 8
  %x.addr = alloca double, align 8
  %y.addr = alloca double, align 8
  %g = alloca double, align 8
  %r = alloca double, align 8
  %u1 = alloca double, align 8
  %u2 = alloca double, align 8
  %v = alloca double, align 8
  %w = alloca double, align 8
  %w1 = alloca double, align 8
  %w2 = alloca double, align 8
  %y1 = alloca double, align 8
  %y2 = alloca double, align 8
  %z = alloca double, align 8
  %iw1 = alloca i32, align 4
  %m = alloca i32, align 4
  %p = alloca i32, align 4
  store double %x, double* %x.addr, align 8
  store double %y, double* %y.addr, align 8
  %1 = load double, double* %y.addr, align 8
  %cmp = fcmp oeq double %1, 0.000000e+00
  br i1 %cmp, label %2, label %3

; <label>:2:                                      ; preds = %0
  store double 1.000000e+00, double* %retval, align 8
  br label %126

; <label>:3:                                      ; preds = %0
  %4 = load double, double* %x.addr, align 8
  %cmp1 = fcmp ole double %4, 0.000000e+00
  br i1 %cmp1, label %5, label %15

; <label>:5:                                      ; preds = %3
  %6 = load double, double* %x.addr, align 8
  %cmp2 = fcmp oeq double %6, 0.000000e+00
  br i1 %cmp2, label %7, label %12

; <label>:7:                                      ; preds = %5
  %8 = load double, double* %y.addr, align 8
  %cmp3 = fcmp ogt double %8, 0.000000e+00
  br i1 %cmp3, label %9, label %11

; <label>:9:                                      ; preds = %7
  %10 = load double, double* %x.addr, align 8
  store double %10, double* %retval, align 8
  br label %126

; <label>:11:                                     ; preds = %7
  store double 0.000000e+00, double* %retval, align 8
  br label %126

; <label>:12:                                     ; preds = %5
  %13 = load double, double* %x.addr, align 8
  %sub = fsub double -0.000000e+00, %13
  store double %sub, double* %x.addr, align 8
  br label %14

; <label>:14:                                     ; preds = %12
  br label %15

; <label>:15:                                     ; preds = %14, %3
  %16 = load double, double* %x.addr, align 8
  %call = call double @frexp(double %16, i32* %m) #3
  store double %call, double* %g, align 8
  store i32 0, i32* %p, align 4
  %17 = load double, double* %g, align 8
  %18 = load double, double* getelementptr inbounds ([17 x double], [17 x double]* @a1, i64 0, i64 8), align 16
  %cmp4 = fcmp ole double %17, %18
  br i1 %cmp4, label %19, label %20

; <label>:19:                                     ; preds = %15
  store i32 8, i32* %p, align 4
  br label %20

; <label>:20:                                     ; preds = %19, %15
  %21 = load double, double* %g, align 8
  %22 = load i32, i32* %p, align 4
  %add = add nsw i32 %22, 4
  %idxprom = sext i32 %add to i64
  %arrayidx = getelementptr inbounds [17 x double], [17 x double]* @a1, i64 0, i64 %idxprom
  %23 = load double, double* %arrayidx, align 8
  %cmp5 = fcmp ole double %21, %23
  br i1 %cmp5, label %24, label %26

; <label>:24:                                     ; preds = %20
  %25 = load i32, i32* %p, align 4
  %add6 = add nsw i32 %25, 4
  store i32 %add6, i32* %p, align 4
  br label %26

; <label>:26:                                     ; preds = %24, %20
  %27 = load double, double* %g, align 8
  %28 = load i32, i32* %p, align 4
  %add7 = add nsw i32 %28, 2
  %idxprom8 = sext i32 %add7 to i64
  %arrayidx9 = getelementptr inbounds [17 x double], [17 x double]* @a1, i64 0, i64 %idxprom8
  %29 = load double, double* %arrayidx9, align 8
  %cmp10 = fcmp ole double %27, %29
  br i1 %cmp10, label %30, label %32

; <label>:30:                                     ; preds = %26
  %31 = load i32, i32* %p, align 4
  %add11 = add nsw i32 %31, 2
  store i32 %add11, i32* %p, align 4
  br label %32

; <label>:32:                                     ; preds = %30, %26
  %33 = load i32, i32* %p, align 4
  %inc = add nsw i32 %33, 1
  store i32 %inc, i32* %p, align 4
  %34 = load double, double* %g, align 8
  %35 = load i32, i32* %p, align 4
  %idxprom12 = sext i32 %35 to i64
  %arrayidx13 = getelementptr inbounds [17 x double], [17 x double]* @a1, i64 0, i64 %idxprom12
  %36 = load double, double* %arrayidx13, align 8
  %sub14 = fsub double %34, %36
  %37 = load i32, i32* %p, align 4
  %div = sdiv i32 %37, 2
  %idxprom15 = sext i32 %div to i64
  %arrayidx16 = getelementptr inbounds [8 x double], [8 x double]* @a2, i64 0, i64 %idxprom15
  %38 = load double, double* %arrayidx16, align 8
  %sub17 = fsub double %sub14, %38
  %39 = load double, double* %g, align 8
  %40 = load i32, i32* %p, align 4
  %idxprom18 = sext i32 %40 to i64
  %arrayidx19 = getelementptr inbounds [17 x double], [17 x double]* @a1, i64 0, i64 %idxprom18
  %41 = load double, double* %arrayidx19, align 8
  %add20 = fadd double %39, %41
  %div21 = fdiv double %sub17, %add20
  store double %div21, double* %z, align 8
  %42 = load double, double* %z, align 8
  %43 = load double, double* %z, align 8
  %add22 = fadd double %43, %42
  store double %add22, double* %z, align 8
  %44 = load double, double* %z, align 8
  %45 = load double, double* %z, align 8
  %mul = fmul double %44, %45
  store double %mul, double* %v, align 8
  %46 = load double, double* @p4, align 8
  %47 = load double, double* %v, align 8
  %mul23 = fmul double %46, %47
  %48 = load double, double* @p3, align 8
  %add24 = fadd double %mul23, %48
  %49 = load double, double* %v, align 8
  %mul25 = fmul double %add24, %49
  %50 = load double, double* @p2, align 8
  %add26 = fadd double %mul25, %50
  %51 = load double, double* %v, align 8
  %mul27 = fmul double %add26, %51
  %52 = load double, double* @p1, align 8
  %add28 = fadd double %mul27, %52
  %53 = load double, double* %v, align 8
  %mul29 = fmul double %add28, %53
  %54 = load double, double* %z, align 8
  %mul30 = fmul double %mul29, %54
  store double %mul30, double* %r, align 8
  %55 = load double, double* @k, align 8
  %56 = load double, double* %r, align 8
  %mul31 = fmul double %55, %56
  %57 = load double, double* %r, align 8
  %add32 = fadd double %57, %mul31
  store double %add32, double* %r, align 8
  %58 = load double, double* %r, align 8
  %59 = load double, double* %z, align 8
  %60 = load double, double* @k, align 8
  %mul33 = fmul double %59, %60
  %add34 = fadd double %58, %mul33
  %61 = load double, double* %z, align 8
  %add35 = fadd double %add34, %61
  store double %add35, double* %u2, align 8
  %62 = load i32, i32* %m, align 4
  %mul36 = mul nsw i32 16, %62
  %63 = load i32, i32* %p, align 4
  %sub37 = sub nsw i32 %mul36, %63
  %conv = sitofp i32 %sub37 to double
  %mul38 = fmul double 6.250000e-02, %conv
  store double %mul38, double* %u1, align 8
  %64 = load double, double* %y.addr, align 8
  %mul39 = fmul double 1.600000e+01, %64
  %conv40 = fptosi double %mul39 to i32
  %conv41 = sitofp i32 %conv40 to double
  %mul42 = fmul double 6.250000e-02, %conv41
  store double %mul42, double* %y1, align 8
  %65 = load double, double* %y.addr, align 8
  %66 = load double, double* %y1, align 8
  %sub43 = fsub double %65, %66
  store double %sub43, double* %y2, align 8
  %67 = load double, double* %u2, align 8
  %68 = load double, double* %y.addr, align 8
  %mul44 = fmul double %67, %68
  %69 = load double, double* %u1, align 8
  %70 = load double, double* %y2, align 8
  %mul45 = fmul double %69, %70
  %add46 = fadd double %mul44, %mul45
  store double %add46, double* %w, align 8
  %71 = load double, double* %w, align 8
  %mul47 = fmul double 1.600000e+01, %71
  %conv48 = fptosi double %mul47 to i32
  %conv49 = sitofp i32 %conv48 to double
  %mul50 = fmul double 6.250000e-02, %conv49
  store double %mul50, double* %w1, align 8
  %72 = load double, double* %w, align 8
  %73 = load double, double* %w1, align 8
  %sub51 = fsub double %72, %73
  store double %sub51, double* %w2, align 8
  %74 = load double, double* %w1, align 8
  %75 = load double, double* %u1, align 8
  %76 = load double, double* %y1, align 8
  %mul52 = fmul double %75, %76
  %add53 = fadd double %74, %mul52
  store double %add53, double* %w, align 8
  %77 = load double, double* %w, align 8
  %mul54 = fmul double 1.600000e+01, %77
  %conv55 = fptosi double %mul54 to i32
  %conv56 = sitofp i32 %conv55 to double
  %mul57 = fmul double 6.250000e-02, %conv56
  store double %mul57, double* %w1, align 8
  %78 = load double, double* %w, align 8
  %79 = load double, double* %w1, align 8
  %sub58 = fsub double %78, %79
  %80 = load double, double* %w2, align 8
  %add59 = fadd double %80, %sub58
  store double %add59, double* %w2, align 8
  %81 = load double, double* %w2, align 8
  %mul60 = fmul double 1.600000e+01, %81
  %conv61 = fptosi double %mul60 to i32
  %conv62 = sitofp i32 %conv61 to double
  %mul63 = fmul double 6.250000e-02, %conv62
  store double %mul63, double* %w, align 8
  %82 = load double, double* %w1, align 8
  %83 = load double, double* %w, align 8
  %add64 = fadd double %82, %83
  %mul65 = fmul double 1.600000e+01, %add64
  %conv66 = fptosi double %mul65 to i32
  store i32 %conv66, i32* %iw1, align 4
  %84 = load double, double* %w, align 8
  %85 = load double, double* %w2, align 8
  %sub67 = fsub double %85, %84
  store double %sub67, double* %w2, align 8
  br label %86

; <label>:86:                                     ; preds = %88, %32
  %87 = load double, double* %w2, align 8
  %cmp68 = fcmp ogt double %87, 0.000000e+00
  br i1 %cmp68, label %88, label %91

; <label>:88:                                     ; preds = %86
  %89 = load i32, i32* %iw1, align 4
  %inc70 = add nsw i32 %89, 1
  store i32 %inc70, i32* %iw1, align 4
  %90 = load double, double* %w2, align 8
  %sub71 = fsub double %90, 6.250000e-02
  store double %sub71, double* %w2, align 8
  br label %86

; <label>:91:                                     ; preds = %86
  %92 = load i32, i32* %iw1, align 4
  %cmp72 = icmp sgt i32 %92, 2031
  br i1 %cmp72, label %93, label %94

; <label>:93:                                     ; preds = %91
  store double 0.000000e+00, double* %retval, align 8
  br label %126

; <label>:94:                                     ; preds = %91
  %95 = load i32, i32* %iw1, align 4
  %cmp74 = icmp slt i32 %95, -2047
  br i1 %cmp74, label %96, label %97

; <label>:96:                                     ; preds = %94
  store double 0.000000e+00, double* %retval, align 8
  br label %126

; <label>:97:                                     ; preds = %94
  %98 = load i32, i32* %iw1, align 4
  %div76 = sdiv i32 %98, 16
  store i32 %div76, i32* %m, align 4
  %99 = load i32, i32* %iw1, align 4
  %cmp77 = icmp sge i32 %99, 0
  br i1 %cmp77, label %100, label %102

; <label>:100:                                    ; preds = %97
  %101 = load i32, i32* %m, align 4
  %inc79 = add nsw i32 %101, 1
  store i32 %inc79, i32* %m, align 4
  br label %102

; <label>:102:                                    ; preds = %100, %97
  %103 = load i32, i32* %m, align 4
  %mul80 = mul nsw i32 16, %103
  %104 = load i32, i32* %iw1, align 4
  %sub81 = sub nsw i32 %mul80, %104
  store i32 %sub81, i32* %p, align 4
  %105 = load double, double* @q7, align 8
  %106 = load double, double* %w2, align 8
  %mul82 = fmul double %105, %106
  %107 = load double, double* @q6, align 8
  %add83 = fadd double %mul82, %107
  %108 = load double, double* %w2, align 8
  %mul84 = fmul double %add83, %108
  %109 = load double, double* @q5, align 8
  %add85 = fadd double %mul84, %109
  %110 = load double, double* %w2, align 8
  %mul86 = fmul double %add85, %110
  %111 = load double, double* @q4, align 8
  %add87 = fadd double %mul86, %111
  %112 = load double, double* %w2, align 8
  %mul88 = fmul double %add87, %112
  %113 = load double, double* @q3, align 8
  %add89 = fadd double %mul88, %113
  %114 = load double, double* %w2, align 8
  %mul90 = fmul double %add89, %114
  %115 = load double, double* @q2, align 8
  %add91 = fadd double %mul90, %115
  %116 = load double, double* %w2, align 8
  %mul92 = fmul double %add91, %116
  %117 = load double, double* @q1, align 8
  %add93 = fadd double %mul92, %117
  %118 = load double, double* %w2, align 8
  %mul94 = fmul double %add93, %118
  store double %mul94, double* %z, align 8
  %119 = load i32, i32* %p, align 4
  %idxprom95 = sext i32 %119 to i64
  %arrayidx96 = getelementptr inbounds [17 x double], [17 x double]* @a1, i64 0, i64 %idxprom95
  %120 = load double, double* %arrayidx96, align 8
  %121 = load i32, i32* %p, align 4
  %idxprom97 = sext i32 %121 to i64
  %arrayidx98 = getelementptr inbounds [17 x double], [17 x double]* @a1, i64 0, i64 %idxprom97
  %122 = load double, double* %arrayidx98, align 8
  %123 = load double, double* %z, align 8
  %mul99 = fmul double %122, %123
  %add100 = fadd double %120, %mul99
  store double %add100, double* %z, align 8
  %124 = load double, double* %z, align 8
  %125 = load i32, i32* %m, align 4
  %call101 = call double @ldexp(double %124, i32 %125) #4
  store double %call101, double* %retval, align 8
  br label %126

; <label>:126:                                    ; preds = %102, %96, %93, %11, %9, %2
  %127 = load double, double* %retval, align 8
  ret double %127
}

; Function Attrs: nounwind
declare double @frexp(double, i32*) #1

; Function Attrs: nounwind readnone
declare double @ldexp(double, i32) #2

; Function Attrs: nounwind
define double @expt(double %p, double %k) #0 {
  %p.addr = alloca double, align 8
  %k.addr = alloca double, align 8
  store double %p, double* %p.addr, align 8
  store double %k, double* %k.addr, align 8
  %1 = load double, double* %p.addr, align 8
  %2 = load double, double* %k.addr, align 8
  %call = call double @expt2(double %1, double %2)
  ret double %call
}

attributes #0 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind readnone "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }
attributes #4 = { nounwind readnone }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.9.1 "}
