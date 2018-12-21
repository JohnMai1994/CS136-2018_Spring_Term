; ModuleID = 'seashell-compiler-output'
source_filename = "seashell-compiler-output"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.trie = type { %struct.trienode* }
%struct.trienode = type { i8, [26 x %struct.trienode*] }

@.str = private unnamed_addr constant [2 x i8] c"s\00", align 1
@.str.1 = private unnamed_addr constant [50 x i8] c"/u1/dtompkins/.seashell/projects/_A10/q3a/_trie.c\00", align 1
@__PRETTY_FUNCTION__.trie_add = private unnamed_addr constant [43 x i8] c"void trie_add(const char *, struct trie *)\00", align 1
@.str.2 = private unnamed_addr constant [2 x i8] c"t\00", align 1
@.str.5 = private unnamed_addr constant [16 x i8] c"valid_letter(c)\00", align 1
@__PRETTY_FUNCTION__.charpos = private unnamed_addr constant [18 x i8] c"int charpos(char)\00", align 1
@__PRETTY_FUNCTION__.trie_remove = private unnamed_addr constant [46 x i8] c"void trie_remove(const char *, struct trie *)\00", align 1
@__PRETTY_FUNCTION__.trie_lookup = private unnamed_addr constant [53 x i8] c"_Bool trie_lookup(const char *, const struct trie *)\00", align 1
@.str.3 = private unnamed_addr constant [30 x i8] c"added_count == expected_count\00", align 1
@__PRETTY_FUNCTION__.trie_to_aos = private unnamed_addr constant [40 x i8] c"char **trie_to_aos(const struct trie *)\00", align 1
@.str.4 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1

; Function Attrs: nounwind
define %struct.trie* @trie_create() #0 {
  %t = alloca %struct.trie*, align 8
  %call = call noalias i8* @malloc(i64 8) #5
  %1 = bitcast i8* %call to %struct.trie*
  store %struct.trie* %1, %struct.trie** %t, align 8
  %2 = load %struct.trie*, %struct.trie** %t, align 8
  %root = getelementptr inbounds %struct.trie, %struct.trie* %2, i32 0, i32 0
  store %struct.trienode* null, %struct.trienode** %root, align 8
  %3 = load %struct.trie*, %struct.trie** %t, align 8
  ret %struct.trie* %3
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

; Function Attrs: nounwind
define void @trie_add(i8* %s, %struct.trie* %t) #0 {
  %s.addr = alloca i8*, align 8
  %t.addr = alloca %struct.trie*, align 8
  %node = alloca %struct.trienode*, align 8
  %pos = alloca i32, align 4
  store i8* %s, i8** %s.addr, align 8
  store %struct.trie* %t, %struct.trie** %t.addr, align 8
  %1 = load i8*, i8** %s.addr, align 8
  %tobool = icmp ne i8* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([50 x i8], [50 x i8]* @.str.1, i32 0, i32 0), i32 40, i8* getelementptr inbounds ([43 x i8], [43 x i8]* @__PRETTY_FUNCTION__.trie_add, i32 0, i32 0)) #6
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %tobool1 = icmp ne %struct.trie* %6, null
  br i1 %tobool1, label %7, label %8

; <label>:7:                                      ; preds = %5
  br label %10

; <label>:8:                                      ; preds = %5
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([50 x i8], [50 x i8]* @.str.1, i32 0, i32 0), i32 41, i8* getelementptr inbounds ([43 x i8], [43 x i8]* @__PRETTY_FUNCTION__.trie_add, i32 0, i32 0)) #6
  unreachable
                                                  ; No predecessors!
  br label %10

; <label>:10:                                     ; preds = %9, %7
  %11 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %root = getelementptr inbounds %struct.trie, %struct.trie* %11, i32 0, i32 0
  %12 = load %struct.trienode*, %struct.trienode** %root, align 8
  %cmp = icmp eq %struct.trienode* %12, null
  br i1 %cmp, label %13, label %15

; <label>:13:                                     ; preds = %10
  %call = call %struct.trienode* @newnode()
  %14 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %root2 = getelementptr inbounds %struct.trie, %struct.trie* %14, i32 0, i32 0
  store %struct.trienode* %call, %struct.trienode** %root2, align 8
  br label %15

; <label>:15:                                     ; preds = %13, %10
  %16 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %root3 = getelementptr inbounds %struct.trie, %struct.trie* %16, i32 0, i32 0
  %17 = load %struct.trienode*, %struct.trienode** %root3, align 8
  store %struct.trienode* %17, %struct.trienode** %node, align 8
  br label %18

; <label>:18:                                     ; preds = %30, %15
  %19 = load i8*, i8** %s.addr, align 8
  %20 = load i8, i8* %19, align 1
  %tobool4 = icmp ne i8 %20, 0
  br i1 %tobool4, label %21, label %35

; <label>:21:                                     ; preds = %18
  %22 = load i8*, i8** %s.addr, align 8
  %23 = load i8, i8* %22, align 1
  %call5 = call i32 @charpos(i8 signext %23)
  store i32 %call5, i32* %pos, align 4
  %24 = load i32, i32* %pos, align 4
  %idxprom = sext i32 %24 to i64
  %25 = load %struct.trienode*, %struct.trienode** %node, align 8
  %children = getelementptr inbounds %struct.trienode, %struct.trienode* %25, i32 0, i32 1
  %arrayidx = getelementptr inbounds [26 x %struct.trienode*], [26 x %struct.trienode*]* %children, i64 0, i64 %idxprom
  %26 = load %struct.trienode*, %struct.trienode** %arrayidx, align 8
  %cmp6 = icmp eq %struct.trienode* %26, null
  br i1 %cmp6, label %27, label %30

; <label>:27:                                     ; preds = %21
  %call7 = call %struct.trienode* @newnode()
  %28 = load i32, i32* %pos, align 4
  %idxprom8 = sext i32 %28 to i64
  %29 = load %struct.trienode*, %struct.trienode** %node, align 8
  %children9 = getelementptr inbounds %struct.trienode, %struct.trienode* %29, i32 0, i32 1
  %arrayidx10 = getelementptr inbounds [26 x %struct.trienode*], [26 x %struct.trienode*]* %children9, i64 0, i64 %idxprom8
  store %struct.trienode* %call7, %struct.trienode** %arrayidx10, align 8
  br label %30

; <label>:30:                                     ; preds = %27, %21
  %31 = load i32, i32* %pos, align 4
  %idxprom11 = sext i32 %31 to i64
  %32 = load %struct.trienode*, %struct.trienode** %node, align 8
  %children12 = getelementptr inbounds %struct.trienode, %struct.trienode* %32, i32 0, i32 1
  %arrayidx13 = getelementptr inbounds [26 x %struct.trienode*], [26 x %struct.trienode*]* %children12, i64 0, i64 %idxprom11
  %33 = load %struct.trienode*, %struct.trienode** %arrayidx13, align 8
  store %struct.trienode* %33, %struct.trienode** %node, align 8
  %34 = load i8*, i8** %s.addr, align 8
  %incdec.ptr = getelementptr inbounds i8, i8* %34, i32 1
  store i8* %incdec.ptr, i8** %s.addr, align 8
  br label %18

; <label>:35:                                     ; preds = %18
  %36 = load %struct.trienode*, %struct.trienode** %node, align 8
  %word_end = getelementptr inbounds %struct.trienode, %struct.trienode* %36, i32 0, i32 0
  store i8 1, i8* %word_end, align 8
  ret void
}

; Function Attrs: noreturn nounwind
declare void @__assert_fail(i8*, i8*, i32, i8*) #2

; Function Attrs: nounwind
define internal %struct.trienode* @newnode() #0 {
  %n = alloca %struct.trienode*, align 8
  %i = alloca i32, align 4
  %call = call noalias i8* @malloc(i64 216) #5
  %1 = bitcast i8* %call to %struct.trienode*
  store %struct.trienode* %1, %struct.trienode** %n, align 8
  %2 = load %struct.trienode*, %struct.trienode** %n, align 8
  %word_end = getelementptr inbounds %struct.trienode, %struct.trienode* %2, i32 0, i32 0
  store i8 0, i8* %word_end, align 8
  store i32 0, i32* %i, align 4
  br label %3

; <label>:3:                                      ; preds = %8, %0
  %4 = load i32, i32* %i, align 4
  %cmp = icmp slt i32 %4, 26
  br i1 %cmp, label %5, label %10

; <label>:5:                                      ; preds = %3
  %6 = load i32, i32* %i, align 4
  %idxprom = sext i32 %6 to i64
  %7 = load %struct.trienode*, %struct.trienode** %n, align 8
  %children = getelementptr inbounds %struct.trienode, %struct.trienode* %7, i32 0, i32 1
  %arrayidx = getelementptr inbounds [26 x %struct.trienode*], [26 x %struct.trienode*]* %children, i64 0, i64 %idxprom
  store %struct.trienode* null, %struct.trienode** %arrayidx, align 8
  br label %8

; <label>:8:                                      ; preds = %5
  %9 = load i32, i32* %i, align 4
  %inc = add nsw i32 %9, 1
  store i32 %inc, i32* %i, align 4
  br label %3

; <label>:10:                                     ; preds = %3
  %11 = load %struct.trienode*, %struct.trienode** %n, align 8
  ret %struct.trienode* %11
}

; Function Attrs: nounwind
define internal i32 @charpos(i8 signext %c) #0 {
  %c.addr = alloca i8, align 1
  store i8 %c, i8* %c.addr, align 1
  %1 = load i8, i8* %c.addr, align 1
  %call = call zeroext i1 @valid_letter(i8 signext %1)
  br i1 %call, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([16 x i8], [16 x i8]* @.str.5, i32 0, i32 0), i8* getelementptr inbounds ([50 x i8], [50 x i8]* @.str.1, i32 0, i32 0), i32 18, i8* getelementptr inbounds ([18 x i8], [18 x i8]* @__PRETTY_FUNCTION__.charpos, i32 0, i32 0)) #6
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load i8, i8* %c.addr, align 1
  %conv = sext i8 %6 to i32
  %sub = sub nsw i32 %conv, 97
  ret i32 %sub
}

; Function Attrs: nounwind
define internal zeroext i1 @valid_letter(i8 signext %c) #0 {
  %c.addr = alloca i8, align 1
  store i8 %c, i8* %c.addr, align 1
  %1 = load i8, i8* %c.addr, align 1
  %conv = sext i8 %1 to i32
  %cmp = icmp sle i32 97, %conv
  br i1 %cmp, label %2, label %4

; <label>:2:                                      ; preds = %0
  %3 = load i8, i8* %c.addr, align 1
  %conv2 = sext i8 %3 to i32
  %cmp3 = icmp sle i32 %conv2, 122
  br label %4

; <label>:4:                                      ; preds = %2, %0
  %5 = phi i1 [ false, %0 ], [ %cmp3, %2 ]
  ret i1 %5
}

; Function Attrs: nounwind
define %struct.trienode* @trienode_remove(i8* %s, %struct.trienode* %node) #0 {
  %s.addr = alloca i8*, align 8
  %node.addr = alloca %struct.trienode*, align 8
  %pos = alloca i32, align 4
  store i8* %s, i8** %s.addr, align 8
  store %struct.trienode* %node, %struct.trienode** %node.addr, align 8
  %1 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %tobool = icmp ne %struct.trienode* %1, null
  br i1 %tobool, label %2, label %22

; <label>:2:                                      ; preds = %0
  %3 = load i8*, i8** %s.addr, align 8
  %4 = load i8, i8* %3, align 1
  %conv = sext i8 %4 to i32
  %cmp = icmp eq i32 %conv, 0
  br i1 %cmp, label %5, label %7

; <label>:5:                                      ; preds = %2
  %6 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %word_end = getelementptr inbounds %struct.trienode, %struct.trienode* %6, i32 0, i32 0
  store i8 0, i8* %word_end, align 8
  br label %16

; <label>:7:                                      ; preds = %2
  %8 = load i8*, i8** %s.addr, align 8
  %9 = load i8, i8* %8, align 1
  %call = call i32 @charpos(i8 signext %9)
  store i32 %call, i32* %pos, align 4
  %10 = load i8*, i8** %s.addr, align 8
  %add.ptr = getelementptr inbounds i8, i8* %10, i64 1
  %11 = load i32, i32* %pos, align 4
  %idxprom = sext i32 %11 to i64
  %12 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %children = getelementptr inbounds %struct.trienode, %struct.trienode* %12, i32 0, i32 1
  %arrayidx = getelementptr inbounds [26 x %struct.trienode*], [26 x %struct.trienode*]* %children, i64 0, i64 %idxprom
  %13 = load %struct.trienode*, %struct.trienode** %arrayidx, align 8
  %call2 = call %struct.trienode* @trienode_remove(i8* %add.ptr, %struct.trienode* %13)
  %14 = load i32, i32* %pos, align 4
  %idxprom3 = sext i32 %14 to i64
  %15 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %children4 = getelementptr inbounds %struct.trienode, %struct.trienode* %15, i32 0, i32 1
  %arrayidx5 = getelementptr inbounds [26 x %struct.trienode*], [26 x %struct.trienode*]* %children4, i64 0, i64 %idxprom3
  store %struct.trienode* %call2, %struct.trienode** %arrayidx5, align 8
  br label %16

; <label>:16:                                     ; preds = %7, %5
  %17 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %call6 = call zeroext i1 @trienode_is_empty(%struct.trienode* %17)
  br i1 %call6, label %18, label %21

; <label>:18:                                     ; preds = %16
  %19 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %20 = bitcast %struct.trienode* %19 to i8*
  call void @free(i8* %20) #5
  store %struct.trienode* null, %struct.trienode** %node.addr, align 8
  br label %21

; <label>:21:                                     ; preds = %18, %16
  br label %22

; <label>:22:                                     ; preds = %21, %0
  %23 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  ret %struct.trienode* %23
}

; Function Attrs: nounwind
define internal zeroext i1 @trienode_is_empty(%struct.trienode* %node) #0 {
  %retval = alloca i1, align 1
  %node.addr = alloca %struct.trienode*, align 8
  %i = alloca i32, align 4
  store %struct.trienode* %node, %struct.trienode** %node.addr, align 8
  %1 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %word_end = getelementptr inbounds %struct.trienode, %struct.trienode* %1, i32 0, i32 0
  %2 = load i8, i8* %word_end, align 8
  %tobool = trunc i8 %2 to i1
  br i1 %tobool, label %3, label %4

; <label>:3:                                      ; preds = %0
  store i1 false, i1* %retval, align 1
  br label %16

; <label>:4:                                      ; preds = %0
  store i32 0, i32* %i, align 4
  br label %5

; <label>:5:                                      ; preds = %13, %4
  %6 = load i32, i32* %i, align 4
  %cmp = icmp slt i32 %6, 26
  br i1 %cmp, label %7, label %15

; <label>:7:                                      ; preds = %5
  %8 = load i32, i32* %i, align 4
  %idxprom = sext i32 %8 to i64
  %9 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %children = getelementptr inbounds %struct.trienode, %struct.trienode* %9, i32 0, i32 1
  %arrayidx = getelementptr inbounds [26 x %struct.trienode*], [26 x %struct.trienode*]* %children, i64 0, i64 %idxprom
  %10 = load %struct.trienode*, %struct.trienode** %arrayidx, align 8
  %tobool1 = icmp ne %struct.trienode* %10, null
  br i1 %tobool1, label %11, label %12

; <label>:11:                                     ; preds = %7
  store i1 false, i1* %retval, align 1
  br label %16

; <label>:12:                                     ; preds = %7
  br label %13

; <label>:13:                                     ; preds = %12
  %14 = load i32, i32* %i, align 4
  %inc = add nsw i32 %14, 1
  store i32 %inc, i32* %i, align 4
  br label %5

; <label>:15:                                     ; preds = %5
  store i1 true, i1* %retval, align 1
  br label %16

; <label>:16:                                     ; preds = %15, %11, %3
  %17 = load i1, i1* %retval, align 1
  ret i1 %17
}

; Function Attrs: nounwind
declare void @free(i8*) #1

; Function Attrs: nounwind
define void @trie_remove(i8* %s, %struct.trie* %t) #0 {
  %s.addr = alloca i8*, align 8
  %t.addr = alloca %struct.trie*, align 8
  store i8* %s, i8** %s.addr, align 8
  store %struct.trie* %t, %struct.trie** %t.addr, align 8
  %1 = load i8*, i8** %s.addr, align 8
  %tobool = icmp ne i8* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([50 x i8], [50 x i8]* @.str.1, i32 0, i32 0), i32 86, i8* getelementptr inbounds ([46 x i8], [46 x i8]* @__PRETTY_FUNCTION__.trie_remove, i32 0, i32 0)) #6
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %tobool1 = icmp ne %struct.trie* %6, null
  br i1 %tobool1, label %7, label %8

; <label>:7:                                      ; preds = %5
  br label %10

; <label>:8:                                      ; preds = %5
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([50 x i8], [50 x i8]* @.str.1, i32 0, i32 0), i32 87, i8* getelementptr inbounds ([46 x i8], [46 x i8]* @__PRETTY_FUNCTION__.trie_remove, i32 0, i32 0)) #6
  unreachable
                                                  ; No predecessors!
  br label %10

; <label>:10:                                     ; preds = %9, %7
  %11 = load i8*, i8** %s.addr, align 8
  %12 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %root = getelementptr inbounds %struct.trie, %struct.trie* %12, i32 0, i32 0
  %13 = load %struct.trienode*, %struct.trienode** %root, align 8
  %call = call %struct.trienode* @trienode_remove(i8* %11, %struct.trienode* %13)
  %14 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %root2 = getelementptr inbounds %struct.trie, %struct.trie* %14, i32 0, i32 0
  store %struct.trienode* %call, %struct.trienode** %root2, align 8
  ret void
}

; Function Attrs: nounwind
define zeroext i1 @trie_lookup(i8* %s, %struct.trie* %t) #0 {
  %s.addr = alloca i8*, align 8
  %t.addr = alloca %struct.trie*, align 8
  %node = alloca %struct.trienode*, align 8
  store i8* %s, i8** %s.addr, align 8
  store %struct.trie* %t, %struct.trie** %t.addr, align 8
  %1 = load i8*, i8** %s.addr, align 8
  %tobool = icmp ne i8* %1, null
  br i1 %tobool, label %2, label %3

; <label>:2:                                      ; preds = %0
  br label %5

; <label>:3:                                      ; preds = %0
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([50 x i8], [50 x i8]* @.str.1, i32 0, i32 0), i32 92, i8* getelementptr inbounds ([53 x i8], [53 x i8]* @__PRETTY_FUNCTION__.trie_lookup, i32 0, i32 0)) #6
  unreachable
                                                  ; No predecessors!
  br label %5

; <label>:5:                                      ; preds = %4, %2
  %6 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %tobool1 = icmp ne %struct.trie* %6, null
  br i1 %tobool1, label %7, label %8

; <label>:7:                                      ; preds = %5
  br label %10

; <label>:8:                                      ; preds = %5
  call void @__assert_fail(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.2, i32 0, i32 0), i8* getelementptr inbounds ([50 x i8], [50 x i8]* @.str.1, i32 0, i32 0), i32 93, i8* getelementptr inbounds ([53 x i8], [53 x i8]* @__PRETTY_FUNCTION__.trie_lookup, i32 0, i32 0)) #6
  unreachable
                                                  ; No predecessors!
  br label %10

; <label>:10:                                     ; preds = %9, %7
  %11 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %root = getelementptr inbounds %struct.trie, %struct.trie* %11, i32 0, i32 0
  %12 = load %struct.trienode*, %struct.trienode** %root, align 8
  store %struct.trienode* %12, %struct.trienode** %node, align 8
  br label %13

; <label>:13:                                     ; preds = %20, %10
  %14 = load %struct.trienode*, %struct.trienode** %node, align 8
  %tobool2 = icmp ne %struct.trienode* %14, null
  br i1 %tobool2, label %15, label %18

; <label>:15:                                     ; preds = %13
  %16 = load i8*, i8** %s.addr, align 8
  %17 = load i8, i8* %16, align 1
  %conv = sext i8 %17 to i32
  %tobool3 = icmp ne i32 %conv, 0
  br label %18

; <label>:18:                                     ; preds = %15, %13
  %19 = phi i1 [ false, %13 ], [ %tobool3, %15 ]
  br i1 %19, label %20, label %26

; <label>:20:                                     ; preds = %18
  %21 = load i8*, i8** %s.addr, align 8
  %22 = load i8, i8* %21, align 1
  %call = call i32 @charpos(i8 signext %22)
  %idxprom = sext i32 %call to i64
  %23 = load %struct.trienode*, %struct.trienode** %node, align 8
  %children = getelementptr inbounds %struct.trienode, %struct.trienode* %23, i32 0, i32 1
  %arrayidx = getelementptr inbounds [26 x %struct.trienode*], [26 x %struct.trienode*]* %children, i64 0, i64 %idxprom
  %24 = load %struct.trienode*, %struct.trienode** %arrayidx, align 8
  store %struct.trienode* %24, %struct.trienode** %node, align 8
  %25 = load i8*, i8** %s.addr, align 8
  %incdec.ptr = getelementptr inbounds i8, i8* %25, i32 1
  store i8* %incdec.ptr, i8** %s.addr, align 8
  br label %13

; <label>:26:                                     ; preds = %18
  %27 = load %struct.trienode*, %struct.trienode** %node, align 8
  %tobool4 = icmp ne %struct.trienode* %27, null
  br i1 %tobool4, label %28, label %31

; <label>:28:                                     ; preds = %26
  %29 = load %struct.trienode*, %struct.trienode** %node, align 8
  %word_end = getelementptr inbounds %struct.trienode, %struct.trienode* %29, i32 0, i32 0
  %30 = load i8, i8* %word_end, align 8
  %tobool5 = trunc i8 %30 to i1
  br label %31

; <label>:31:                                     ; preds = %28, %26
  %32 = phi i1 [ false, %26 ], [ %tobool5, %28 ]
  ret i1 %32
}

; Function Attrs: nounwind
define void @trie_destroy(%struct.trie* %t) #0 {
  %t.addr = alloca %struct.trie*, align 8
  store %struct.trie* %t, %struct.trie** %t.addr, align 8
  %1 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %root = getelementptr inbounds %struct.trie, %struct.trie* %1, i32 0, i32 0
  %2 = load %struct.trienode*, %struct.trienode** %root, align 8
  call void @trienode_free(%struct.trienode* %2)
  %3 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %4 = bitcast %struct.trie* %3 to i8*
  call void @free(i8* %4) #5
  ret void
}

; Function Attrs: nounwind
define internal void @trienode_free(%struct.trienode* %node) #0 {
  %node.addr = alloca %struct.trienode*, align 8
  %i = alloca i32, align 4
  store %struct.trienode* %node, %struct.trienode** %node.addr, align 8
  %1 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %tobool = icmp ne %struct.trienode* %1, null
  br i1 %tobool, label %2, label %14

; <label>:2:                                      ; preds = %0
  store i32 0, i32* %i, align 4
  br label %3

; <label>:3:                                      ; preds = %9, %2
  %4 = load i32, i32* %i, align 4
  %cmp = icmp slt i32 %4, 26
  br i1 %cmp, label %5, label %11

; <label>:5:                                      ; preds = %3
  %6 = load i32, i32* %i, align 4
  %idxprom = sext i32 %6 to i64
  %7 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %children = getelementptr inbounds %struct.trienode, %struct.trienode* %7, i32 0, i32 1
  %arrayidx = getelementptr inbounds [26 x %struct.trienode*], [26 x %struct.trienode*]* %children, i64 0, i64 %idxprom
  %8 = load %struct.trienode*, %struct.trienode** %arrayidx, align 8
  call void @trienode_free(%struct.trienode* %8)
  br label %9

; <label>:9:                                      ; preds = %5
  %10 = load i32, i32* %i, align 4
  %inc = add nsw i32 %10, 1
  store i32 %inc, i32* %i, align 4
  br label %3

; <label>:11:                                     ; preds = %3
  %12 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %13 = bitcast %struct.trienode* %12 to i8*
  call void @free(i8* %13) #5
  br label %14

; <label>:14:                                     ; preds = %11, %0
  ret void
}

; Function Attrs: nounwind
define i32 @trie_count(%struct.trie* %t) #0 {
  %t.addr = alloca %struct.trie*, align 8
  store %struct.trie* %t, %struct.trie** %t.addr, align 8
  %1 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %root = getelementptr inbounds %struct.trie, %struct.trie* %1, i32 0, i32 0
  %2 = load %struct.trienode*, %struct.trienode** %root, align 8
  %call = call i32 @trienode_count(%struct.trienode* %2)
  ret i32 %call
}

; Function Attrs: nounwind
define internal i32 @trienode_count(%struct.trienode* %node) #0 {
  %node.addr = alloca %struct.trienode*, align 8
  %count = alloca i32, align 4
  %i = alloca i32, align 4
  store %struct.trienode* %node, %struct.trienode** %node.addr, align 8
  store i32 0, i32* %count, align 4
  %1 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %tobool = icmp ne %struct.trienode* %1, null
  br i1 %tobool, label %2, label %16

; <label>:2:                                      ; preds = %0
  %3 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %word_end = getelementptr inbounds %struct.trienode, %struct.trienode* %3, i32 0, i32 0
  %4 = load i8, i8* %word_end, align 8
  %tobool1 = trunc i8 %4 to i1
  %conv = zext i1 %tobool1 to i32
  %5 = load i32, i32* %count, align 4
  %add = add nsw i32 %5, %conv
  store i32 %add, i32* %count, align 4
  store i32 0, i32* %i, align 4
  br label %6

; <label>:6:                                      ; preds = %13, %2
  %7 = load i32, i32* %i, align 4
  %cmp = icmp slt i32 %7, 26
  br i1 %cmp, label %8, label %15

; <label>:8:                                      ; preds = %6
  %9 = load i32, i32* %i, align 4
  %idxprom = sext i32 %9 to i64
  %10 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %children = getelementptr inbounds %struct.trienode, %struct.trienode* %10, i32 0, i32 1
  %arrayidx = getelementptr inbounds [26 x %struct.trienode*], [26 x %struct.trienode*]* %children, i64 0, i64 %idxprom
  %11 = load %struct.trienode*, %struct.trienode** %arrayidx, align 8
  %call = call i32 @trienode_count(%struct.trienode* %11)
  %12 = load i32, i32* %count, align 4
  %add3 = add nsw i32 %12, %call
  store i32 %add3, i32* %count, align 4
  br label %13

; <label>:13:                                     ; preds = %8
  %14 = load i32, i32* %i, align 4
  %inc = add nsw i32 %14, 1
  store i32 %inc, i32* %i, align 4
  br label %6

; <label>:15:                                     ; preds = %6
  br label %16

; <label>:16:                                     ; preds = %15, %0
  %17 = load i32, i32* %count, align 4
  ret i32 %17
}

; Function Attrs: nounwind
define i8** @trie_to_aos(%struct.trie* %t) #0 {
  %retval = alloca i8**, align 8
  %t.addr = alloca %struct.trie*, align 8
  %expected_count = alloca i32, align 4
  %aos = alloca i8**, align 8
  %empty = alloca i8*, align 8
  %added_count = alloca i32, align 4
  store %struct.trie* %t, %struct.trie** %t.addr, align 8
  %1 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %call = call i32 @trie_count(%struct.trie* %1)
  store i32 %call, i32* %expected_count, align 4
  %2 = load i32, i32* %expected_count, align 4
  %cmp = icmp eq i32 %2, 0
  br i1 %cmp, label %3, label %4

; <label>:3:                                      ; preds = %0
  store i8** null, i8*** %retval, align 8
  br label %19

; <label>:4:                                      ; preds = %0
  %5 = load i32, i32* %expected_count, align 4
  %conv = sext i32 %5 to i64
  %mul = mul i64 %conv, 8
  %call1 = call noalias i8* @malloc(i64 %mul) #5
  %6 = bitcast i8* %call1 to i8**
  store i8** %6, i8*** %aos, align 8
  %call2 = call noalias i8* @malloc(i64 1) #5
  store i8* %call2, i8** %empty, align 8
  %7 = load i8*, i8** %empty, align 8
  store i8 0, i8* %7, align 1
  store i32 0, i32* %added_count, align 4
  %8 = load i8**, i8*** %aos, align 8
  %9 = load i8*, i8** %empty, align 8
  %10 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %root = getelementptr inbounds %struct.trie, %struct.trie* %10, i32 0, i32 0
  %11 = load %struct.trienode*, %struct.trienode** %root, align 8
  call void @trienode_to_aos(i8** %8, i32* %added_count, i8* %9, %struct.trienode* %11)
  %12 = load i32, i32* %added_count, align 4
  %13 = load i32, i32* %expected_count, align 4
  %cmp3 = icmp eq i32 %12, %13
  br i1 %cmp3, label %14, label %15

; <label>:14:                                     ; preds = %4
  br label %17

; <label>:15:                                     ; preds = %4
  call void @__assert_fail(i8* getelementptr inbounds ([30 x i8], [30 x i8]* @.str.3, i32 0, i32 0), i8* getelementptr inbounds ([50 x i8], [50 x i8]* @.str.1, i32 0, i32 0), i32 168, i8* getelementptr inbounds ([40 x i8], [40 x i8]* @__PRETTY_FUNCTION__.trie_to_aos, i32 0, i32 0)) #6
  unreachable
                                                  ; No predecessors!
  br label %17

; <label>:17:                                     ; preds = %16, %14
  %18 = load i8**, i8*** %aos, align 8
  store i8** %18, i8*** %retval, align 8
  br label %19

; <label>:19:                                     ; preds = %17, %3
  %20 = load i8**, i8*** %retval, align 8
  ret i8** %20
}

; Function Attrs: nounwind
define internal void @trienode_to_aos(i8** %aos, i32* %count, i8* %sofar, %struct.trienode* %node) #0 {
  %aos.addr = alloca i8**, align 8
  %count.addr = alloca i32*, align 8
  %sofar.addr = alloca i8*, align 8
  %node.addr = alloca %struct.trienode*, align 8
  %len = alloca i32, align 4
  %i = alloca i32, align 4
  %next = alloca i8*, align 8
  store i8** %aos, i8*** %aos.addr, align 8
  store i32* %count, i32** %count.addr, align 8
  store i8* %sofar, i8** %sofar.addr, align 8
  store %struct.trienode* %node, %struct.trienode** %node.addr, align 8
  %1 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %tobool = icmp ne %struct.trienode* %1, null
  br i1 %tobool, label %2, label %44

; <label>:2:                                      ; preds = %0
  %3 = load i8*, i8** %sofar.addr, align 8
  %call = call i64 @strlen(i8* %3) #7
  %conv = trunc i64 %call to i32
  store i32 %conv, i32* %len, align 4
  %4 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %word_end = getelementptr inbounds %struct.trienode, %struct.trienode* %4, i32 0, i32 0
  %5 = load i8, i8* %word_end, align 8
  %tobool1 = trunc i8 %5 to i1
  br i1 %tobool1, label %6, label %13

; <label>:6:                                      ; preds = %2
  %7 = load i8*, i8** %sofar.addr, align 8
  %8 = load i32*, i32** %count.addr, align 8
  %9 = load i32, i32* %8, align 4
  %idxprom = sext i32 %9 to i64
  %10 = load i8**, i8*** %aos.addr, align 8
  %arrayidx = getelementptr inbounds i8*, i8** %10, i64 %idxprom
  store i8* %7, i8** %arrayidx, align 8
  %11 = load i32*, i32** %count.addr, align 8
  %12 = load i32, i32* %11, align 4
  %add = add nsw i32 %12, 1
  store i32 %add, i32* %11, align 4
  br label %13

; <label>:13:                                     ; preds = %6, %2
  store i32 0, i32* %i, align 4
  br label %14

; <label>:14:                                     ; preds = %36, %13
  %15 = load i32, i32* %i, align 4
  %cmp = icmp slt i32 %15, 26
  br i1 %cmp, label %16, label %38

; <label>:16:                                     ; preds = %14
  %17 = load i32, i32* %i, align 4
  %idxprom3 = sext i32 %17 to i64
  %18 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %children = getelementptr inbounds %struct.trienode, %struct.trienode* %18, i32 0, i32 1
  %arrayidx4 = getelementptr inbounds [26 x %struct.trienode*], [26 x %struct.trienode*]* %children, i64 0, i64 %idxprom3
  %19 = load %struct.trienode*, %struct.trienode** %arrayidx4, align 8
  %tobool5 = icmp ne %struct.trienode* %19, null
  br i1 %tobool5, label %20, label %35

; <label>:20:                                     ; preds = %16
  %21 = load i32, i32* %len, align 4
  %add6 = add nsw i32 %21, 2
  %conv7 = sext i32 %add6 to i64
  %mul = mul i64 %conv7, 1
  %call8 = call noalias i8* @malloc(i64 %mul) #5
  store i8* %call8, i8** %next, align 8
  %22 = load i8*, i8** %next, align 8
  %23 = load i8*, i8** %sofar.addr, align 8
  %call9 = call i8* @strcpy(i8* %22, i8* %23) #5
  %24 = load i32, i32* %i, align 4
  %add10 = add nsw i32 97, %24
  %conv11 = trunc i32 %add10 to i8
  %25 = load i32, i32* %len, align 4
  %idxprom12 = sext i32 %25 to i64
  %26 = load i8*, i8** %next, align 8
  %arrayidx13 = getelementptr inbounds i8, i8* %26, i64 %idxprom12
  store i8 %conv11, i8* %arrayidx13, align 1
  %27 = load i32, i32* %len, align 4
  %add14 = add nsw i32 %27, 1
  %idxprom15 = sext i32 %add14 to i64
  %28 = load i8*, i8** %next, align 8
  %arrayidx16 = getelementptr inbounds i8, i8* %28, i64 %idxprom15
  store i8 0, i8* %arrayidx16, align 1
  %29 = load i8**, i8*** %aos.addr, align 8
  %30 = load i32*, i32** %count.addr, align 8
  %31 = load i8*, i8** %next, align 8
  %32 = load i32, i32* %i, align 4
  %idxprom17 = sext i32 %32 to i64
  %33 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %children18 = getelementptr inbounds %struct.trienode, %struct.trienode* %33, i32 0, i32 1
  %arrayidx19 = getelementptr inbounds [26 x %struct.trienode*], [26 x %struct.trienode*]* %children18, i64 0, i64 %idxprom17
  %34 = load %struct.trienode*, %struct.trienode** %arrayidx19, align 8
  call void @trienode_to_aos(i8** %29, i32* %30, i8* %31, %struct.trienode* %34)
  br label %35

; <label>:35:                                     ; preds = %20, %16
  br label %36

; <label>:36:                                     ; preds = %35
  %37 = load i32, i32* %i, align 4
  %inc = add nsw i32 %37, 1
  store i32 %inc, i32* %i, align 4
  br label %14

; <label>:38:                                     ; preds = %14
  %39 = load %struct.trienode*, %struct.trienode** %node.addr, align 8
  %word_end20 = getelementptr inbounds %struct.trienode, %struct.trienode* %39, i32 0, i32 0
  %40 = load i8, i8* %word_end20, align 8
  %tobool21 = trunc i8 %40 to i1
  br i1 %tobool21, label %43, label %41

; <label>:41:                                     ; preds = %38
  %42 = load i8*, i8** %sofar.addr, align 8
  call void @free(i8* %42) #5
  br label %43

; <label>:43:                                     ; preds = %41, %38
  br label %44

; <label>:44:                                     ; preds = %43, %0
  ret void
}

; Function Attrs: nounwind readonly
declare i64 @strlen(i8*) #3

; Function Attrs: nounwind
declare i8* @strcpy(i8*, i8*) #1

; Function Attrs: nounwind
define void @trie_print(%struct.trie* %t) #0 {
  %t.addr = alloca %struct.trie*, align 8
  %aos = alloca i8**, align 8
  %count = alloca i32, align 4
  %i = alloca i32, align 4
  store %struct.trie* %t, %struct.trie** %t.addr, align 8
  %1 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %call = call i8** @trie_to_aos(%struct.trie* %1)
  store i8** %call, i8*** %aos, align 8
  %2 = load i8**, i8*** %aos, align 8
  %tobool = icmp ne i8** %2, null
  br i1 %tobool, label %3, label %20

; <label>:3:                                      ; preds = %0
  %4 = load %struct.trie*, %struct.trie** %t.addr, align 8
  %call1 = call i32 @trie_count(%struct.trie* %4)
  store i32 %call1, i32* %count, align 4
  store i32 0, i32* %i, align 4
  br label %5

; <label>:5:                                      ; preds = %15, %3
  %6 = load i32, i32* %i, align 4
  %7 = load i32, i32* %count, align 4
  %cmp = icmp slt i32 %6, %7
  br i1 %cmp, label %8, label %17

; <label>:8:                                      ; preds = %5
  %9 = load i32, i32* %i, align 4
  %idxprom = sext i32 %9 to i64
  %10 = load i8**, i8*** %aos, align 8
  %arrayidx = getelementptr inbounds i8*, i8** %10, i64 %idxprom
  %11 = load i8*, i8** %arrayidx, align 8
  %call2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str.4, i32 0, i32 0), i8* %11)
  %12 = load i32, i32* %i, align 4
  %idxprom3 = sext i32 %12 to i64
  %13 = load i8**, i8*** %aos, align 8
  %arrayidx4 = getelementptr inbounds i8*, i8** %13, i64 %idxprom3
  %14 = load i8*, i8** %arrayidx4, align 8
  call void @free(i8* %14) #5
  br label %15

; <label>:15:                                     ; preds = %8
  %16 = load i32, i32* %i, align 4
  %inc = add nsw i32 %16, 1
  store i32 %inc, i32* %i, align 4
  br label %5

; <label>:17:                                     ; preds = %5
  %18 = load i8**, i8*** %aos, align 8
  %19 = bitcast i8** %18 to i8*
  call void @free(i8* %19) #5
  br label %20

; <label>:20:                                     ; preds = %17, %0
  ret void
}

declare i32 @printf(i8*, ...) #4

attributes #0 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noreturn nounwind "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind readonly "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { nounwind }
attributes #6 = { noreturn nounwind }
attributes #7 = { nounwind readonly }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.9.1 "}
