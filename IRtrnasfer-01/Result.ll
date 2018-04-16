; ModuleID = 'Result.bc'
source_filename = "./check/cg_example.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@SpecificMem = global i32 0, align 4
@Sum = global i32 0, align 4
@0 = private unnamed_addr constant [15 x i8] c"Checker1 run!\0A\00"
@1 = private unnamed_addr constant [15 x i8] c"Checker2 run!\0A\00"
@2 = private unnamed_addr constant [15 x i8] c"Checker3 run!\0A\00"
@3 = private unnamed_addr constant [15 x i8] c"Checker4 run!\0A\00"
@4 = private unnamed_addr constant [15 x i8] c"Checker5 run!\0A\00"

; Function Attrs: noinline nounwind optnone uwtable
define void @func1() #0 {
  call void @checker1()
  %1 = alloca i32, align 4
  store i32 1, i32* %1, align 4
  %2 = load i32, i32* @SpecificMem, align 4
  %3 = icmp eq i32 %2, 1
  br i1 %3, label %4, label %16

; <label>:4:                                      ; preds = %0
  %5 = load i32, i32* %1, align 4
  %6 = icmp eq i32 %5, 1
  br i1 %6, label %7, label %11

; <label>:7:                                      ; preds = %4
  %8 = load i32, i32* @SpecificMem, align 4
  %9 = load i32, i32* @Sum, align 4
  %10 = add nsw i32 %9, %8
  store i32 %10, i32* @Sum, align 4
  br label %15

; <label>:11:                                     ; preds = %4
  %12 = load i32, i32* @SpecificMem, align 4
  %13 = load i32, i32* @Sum, align 4
  %14 = sub nsw i32 %13, %12
  store i32 %14, i32* @Sum, align 4
  br label %15

; <label>:15:                                     ; preds = %11, %7
  br label %16

; <label>:16:                                     ; preds = %15, %0
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define void @func2() #0 {
  call void @checker2()
  %1 = alloca i32, align 4
  store i32 1, i32* %1, align 4
  %2 = load i32, i32* @SpecificMem, align 4
  %3 = icmp eq i32 %2, 1
  br i1 %3, label %4, label %16

; <label>:4:                                      ; preds = %0
  %5 = load i32, i32* %1, align 4
  %6 = icmp eq i32 %5, 1
  br i1 %6, label %7, label %11

; <label>:7:                                      ; preds = %4
  %8 = load i32, i32* @SpecificMem, align 4
  %9 = load i32, i32* @Sum, align 4
  %10 = add nsw i32 %9, %8
  store i32 %10, i32* @Sum, align 4
  br label %15

; <label>:11:                                     ; preds = %4
  %12 = load i32, i32* @SpecificMem, align 4
  %13 = load i32, i32* @Sum, align 4
  %14 = sub nsw i32 %13, %12
  store i32 %14, i32* @Sum, align 4
  br label %15

; <label>:15:                                     ; preds = %11, %7
  br label %16

; <label>:16:                                     ; preds = %15, %0
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define void @func3() #0 {
  call void @checker3()
  %1 = alloca i32, align 4
  store i32 1, i32* %1, align 4
  %2 = load i32, i32* @SpecificMem, align 4
  %3 = icmp eq i32 %2, 1
  br i1 %3, label %4, label %16

; <label>:4:                                      ; preds = %0
  %5 = load i32, i32* %1, align 4
  %6 = icmp eq i32 %5, 1
  br i1 %6, label %7, label %11

; <label>:7:                                      ; preds = %4
  %8 = load i32, i32* @SpecificMem, align 4
  %9 = load i32, i32* @Sum, align 4
  %10 = add nsw i32 %9, %8
  store i32 %10, i32* @Sum, align 4
  br label %15

; <label>:11:                                     ; preds = %4
  %12 = load i32, i32* @SpecificMem, align 4
  %13 = load i32, i32* @Sum, align 4
  %14 = sub nsw i32 %13, %12
  store i32 %14, i32* @Sum, align 4
  br label %15

; <label>:15:                                     ; preds = %11, %7
  br label %16

; <label>:16:                                     ; preds = %15, %0
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define void @func4() #0 {
  call void @checker4()
  %1 = alloca i32, align 4
  store i32 1, i32* %1, align 4
  %2 = load i32, i32* @SpecificMem, align 4
  %3 = icmp eq i32 %2, 1
  br i1 %3, label %4, label %16

; <label>:4:                                      ; preds = %0
  %5 = load i32, i32* %1, align 4
  %6 = icmp eq i32 %5, 1
  br i1 %6, label %7, label %11

; <label>:7:                                      ; preds = %4
  %8 = load i32, i32* @SpecificMem, align 4
  %9 = load i32, i32* @Sum, align 4
  %10 = add nsw i32 %9, %8
  store i32 %10, i32* @Sum, align 4
  br label %15

; <label>:11:                                     ; preds = %4
  %12 = load i32, i32* @SpecificMem, align 4
  %13 = load i32, i32* @Sum, align 4
  %14 = sub nsw i32 %13, %12
  store i32 %14, i32* @Sum, align 4
  br label %15

; <label>:15:                                     ; preds = %11, %7
  br label %16

; <label>:16:                                     ; preds = %15, %0
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define void @func5() #0 {
  call void @checker5()
  %1 = alloca i32, align 4
  store i32 1, i32* %1, align 4
  %2 = load i32, i32* @SpecificMem, align 4
  %3 = icmp eq i32 %2, 1
  br i1 %3, label %4, label %16

; <label>:4:                                      ; preds = %0
  %5 = load i32, i32* %1, align 4
  %6 = icmp eq i32 %5, 1
  br i1 %6, label %7, label %11

; <label>:7:                                      ; preds = %4
  %8 = load i32, i32* @SpecificMem, align 4
  %9 = load i32, i32* @Sum, align 4
  %10 = add nsw i32 %9, %8
  store i32 %10, i32* @Sum, align 4
  br label %15

; <label>:11:                                     ; preds = %4
  %12 = load i32, i32* @SpecificMem, align 4
  %13 = load i32, i32* @Sum, align 4
  %14 = sub nsw i32 %13, %12
  store i32 %14, i32* @Sum, align 4
  br label %15

; <label>:15:                                     ; preds = %11, %7
  br label %16

; <label>:16:                                     ; preds = %15, %0
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  store i32 1, i32* @SpecificMem, align 4
  %2 = load i32, i32* @SpecificMem, align 4
  %3 = load i32, i32* @Sum, align 4
  %4 = add nsw i32 %3, %2
  store i32 %4, i32* @Sum, align 4
  call void @func1()
  br label %5

; <label>:5:                                      ; preds = %0
  call void @func2()
  br label %6

; <label>:6:                                      ; preds = %5
  call void @func3()
  br label %7

; <label>:7:                                      ; preds = %6
  call void @func4()
  br label %8

; <label>:8:                                      ; preds = %7
  call void @func5()
  br label %9

; <label>:9:                                      ; preds = %8
  ret i32 0
}

define i32 @checker0(i32 %x, i32 %y, i32 %z) {
entry:
  %tmp = mul i32 %x, %y
  %temp2 = add i32 %tmp, %z
  ret i32 %temp2
}

declare i32 @puts(i8*)

define void @checker1() {
entry:
  %0 = call i32 @puts(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @0, i32 0, i32 0))
  ret void
}

define void @checker2() {
entry:
  %0 = call i32 @puts(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @1, i32 0, i32 0))
  ret void
}

define void @checker3() {
entry:
  %0 = call i32 @puts(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @2, i32 0, i32 0))
  ret void
}

define void @checker4() {
entry:
  %0 = call i32 @puts(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @3, i32 0, i32 0))
  ret void
}

define void @checker5() {
entry:
  %0 = call i32 @puts(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @4, i32 0, i32 0))
  ret void
}

define void @CallcheckerSet() {
entry:
  call void @checker1()
  call void @checker2()
  call void @checker3()
  call void @checker4()
  call void @checker5()
  ret void
}

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 5.0.0 (tags/RELEASE_500/final)"}
