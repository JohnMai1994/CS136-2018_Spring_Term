; ModuleID = 'seashell-compiler-output'
source_filename = "seashell-compiler-output"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.wordlist = type { i32, %struct.trie* }
%struct.trie = type { %struct.trienode* }
%struct.trienode = type { i8, [26 x %struct.trienode*] }

@.str = private unnamed_addr constant [3 x i8] c"wl\00", align 1
@.str.1 = private unnamed_addr constant [54 x i8] c"/u1/dtompkins/.seashell/projects/_A10/q3b/_wordlist.c\00", align 1
@__PRETTY_FUNCTION__.wordlist_add = private unnamed_addr constant [51 x i8] c"void wordlist_add(const char *, struct wordlist *)\00", align 1
@__PRETTY_FUNCTION__.wordlist_lookup = private unnamed_addr constant [61 x i8] c"_Bool wordlist_lookup(const char *, const struct wordlist *)\00", align 1
@__PRETTY_FUNCTION__.wordlist_remove = private unnamed_addr constant [54 x i8] c"void wordlist_remove(const char *, struct wordlist *)\00", align 1
@__PRETTY_FUNCTION__.wordlist_destroy = private unnamed_addr constant [41 x i8] c"void wordlist_destroy(struct wordlist *)\00", align 1
@__PRETTY_FUNCTION__.wordlist_print = private unnamed_addr constant [45 x i8] c"void wordlist_print(const struct wordlist *)\00", align 1

; Function Attrs: nounwind
define %struct.wordlist* @wordlist_create() #0 {
  %wl = alloca %struct.wordlist*, align 8
  %call = call noalias i8* @malloc(i64 16) #4
  %1 = bitcast i8* %call to %struct.wordlist*
  store %struct.wordlist* %1, %struct.wordlist** %wl, align 8
  %2 = load %struct.wordlist*, %struct.wordlist** %wl, align 8
  %count = getelementptr inbounds %struct.wordlist, %struct.wordlist* %2, i32 0, i32 0
  store i32 0, i32* %count, align 8
  %call1 = call %struct.trie* @trie_create()
  %3 = load %struct.wordlist*, %struct.wordlist** %wl, align 8
  %t = getelementptr inbounds %struct.wordlist, %struct.wordlist* %3, i32 0, i32 1
  store %struct.trie* %call1, %struct.trie** %t, align 8
  %4 = load %struct.wordlist*, %struct.wordlist** %wl, align 8
  ret %struct.wordlist* %4
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

declare %struct.trie* @trie_create() #2

; Function Attrs: nounwind
define void @wordlist_add(i8* %s, %struct.wordlist* %wl) #0 {
  %s.addr = alloca i8*, align 8
  %wl.addr = alloca %struct.wordlist*, align 8
  store i8* %s, i8** %s.addr, align 8
  store %struct.wordlist* %wl, %struct.wordlist** %wl.addr, align 8
  %1 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %tobool = icmp ne %struct.wordlist* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([54 x i8], [54 x i8]* @.str.1, i32 0, i32 0), i32 19, i8* getelementptr inbounds ([51 x i8], [51 x i8]* @__PRETTY_FUNCTION__.wordlist_add, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load i8*, i8** %s.addr, align 8
  %7 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %call = call zeroext i1 @wordlist_lookup(i8* %6, %struct.wordlist* %7)
  br i1 %call, label %14, label %8

; <label>:8:                                      ; preds = %5
  %9 = load i8*, i8** %s.addr, align 8
  %10 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %t = getelementptr inbounds %struct.wordlist, %struct.wordlist* %10, i32 0, i32 1
  %11 = load %struct.trie*, %struct.trie** %t, align 8
  call void @trie_add(i8* %9, %struct.trie* %11)
  %12 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %count = getelementptr inbounds %struct.wordlist, %struct.wordlist* %12, i32 0, i32 0
  %13 = load i32, i32* %count, align 8
  %add = add nsw i32 %13, 1
  store i32 %add, i32* %count, align 8
  br label %14

; <label>:14:                                     ; preds = %8, %5
  ret void
}

; Function Attrs: noreturn nounwind
declare void @__assert_fail(i8*, i8*, i32, i8*) #3

; Function Attrs: nounwind
define zeroext i1 @wordlist_lookup(i8* %s, %struct.wordlist* %wl) #0 {
  %s.addr = alloca i8*, align 8
  %wl.addr = alloca %struct.wordlist*, align 8
  store i8* %s, i8** %s.addr, align 8
  store %struct.wordlist* %wl, %struct.wordlist** %wl.addr, align 8
  %1 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %tobool = icmp ne %struct.wordlist* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([54 x i8], [54 x i8]* @.str.1, i32 0, i32 0), i32 35, i8* getelementptr inbounds ([61 x i8], [61 x i8]* @__PRETTY_FUNCTION__.wordlist_lookup, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load i8*, i8** %s.addr, align 8
  %7 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %t = getelementptr inbounds %struct.wordlist, %struct.wordlist* %7, i32 0, i32 1
  %8 = load %struct.trie*, %struct.trie** %t, align 8
  %call = call zeroext i1 @trie_lookup(i8* %6, %struct.trie* %8)
  ret i1 %call
}

declare void @trie_add(i8*, %struct.trie*) #2

declare zeroext i1 @trie_lookup(i8*, %struct.trie*) #2

; Function Attrs: nounwind
define void @wordlist_remove(i8* %s, %struct.wordlist* %wl) #0 {
  %s.addr = alloca i8*, align 8
  %wl.addr = alloca %struct.wordlist*, align 8
  store i8* %s, i8** %s.addr, align 8
  store %struct.wordlist* %wl, %struct.wordlist** %wl.addr, align 8
  %1 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %tobool = icmp ne %struct.wordlist* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([54 x i8], [54 x i8]* @.str.1, i32 0, i32 0), i32 27, i8* getelementptr inbounds ([54 x i8], [54 x i8]* @__PRETTY_FUNCTION__.wordlist_remove, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load i8*, i8** %s.addr, align 8
  %7 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %call = call zeroext i1 @wordlist_lookup(i8* %6, %struct.wordlist* %7)
  br i1 %call, label %8, label %14

; <label>:8:                                      ; preds = %5
  %9 = load i8*, i8** %s.addr, align 8
  %10 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %t = getelementptr inbounds %struct.wordlist, %struct.wordlist* %10, i32 0, i32 1
  %11 = load %struct.trie*, %struct.trie** %t, align 8
  call void @trie_remove(i8* %9, %struct.trie* %11)
  %12 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %count = getelementptr inbounds %struct.wordlist, %struct.wordlist* %12, i32 0, i32 0
  %13 = load i32, i32* %count, align 8
  %sub = sub nsw i32 %13, 1
  store i32 %sub, i32* %count, align 8
  br label %14

; <label>:14:                                     ; preds = %8, %5
  ret void
}

declare void @trie_remove(i8*, %struct.trie*) #2

; Function Attrs: nounwind
define void @wordlist_destroy(%struct.wordlist* %wl) #0 {
  %wl.addr = alloca %struct.wordlist*, align 8
  store %struct.wordlist* %wl, %struct.wordlist** %wl.addr, align 8
  %1 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %tobool = icmp ne %struct.wordlist* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([54 x i8], [54 x i8]* @.str.1, i32 0, i32 0), i32 40, i8* getelementptr inbounds ([41 x i8], [41 x i8]* @__PRETTY_FUNCTION__.wordlist_destroy, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %t = getelementptr inbounds %struct.wordlist, %struct.wordlist* %6, i32 0, i32 1
  %7 = load %struct.trie*, %struct.trie** %t, align 8
  call void @trie_destroy(%struct.trie* %7)
  %8 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %9 = bitcast %struct.wordlist* %8 to i8*
  call void @free(i8* %9) #4
  ret void
}

declare void @trie_destroy(%struct.trie*) #2

; Function Attrs: nounwind
declare void @free(i8*) #1

; Function Attrs: nounwind
define void @wordlist_print(%struct.wordlist* %wl) #0 {
  %wl.addr = alloca %struct.wordlist*, align 8
  store %struct.wordlist* %wl, %struct.wordlist** %wl.addr, align 8
  %1 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %tobool = icmp ne %struct.wordlist* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([54 x i8], [54 x i8]* @.str.1, i32 0, i32 0), i32 46, i8* getelementptr inbounds ([45 x i8], [45 x i8]* @__PRETTY_FUNCTION__.wordlist_print, i32 0, i32 0)) #5
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %t = getelementptr inbounds %struct.wordlist, %struct.wordlist* %6, i32 0, i32 1
  %7 = load %struct.trie*, %struct.trie** %t, align 8
  call void @trie_print(%struct.trie* %7)
  ret void
}

declare void @trie_print(%struct.trie*) #2

; Function Attrs: nounwind
define i32 @wordlist_count(%struct.wordlist* %wl) #0 {
  %wl.addr = alloca %struct.wordlist*, align 8
  store %struct.wordlist* %wl, %struct.wordlist** %wl.addr, align 8
  %1 = load %struct.wordlist*, %struct.wordlist** %wl.addr, align 8
  %count = getelementptr inbounds %struct.wordlist, %struct.wordlist* %1, i32 0, i32 0
  %2 = load i32, i32* %count, align 8
  ret i32 %2
}

attributes #0 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noreturn nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind }
attributes #5 = { noreturn nounwind }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.9.1 "}
