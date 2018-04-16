; ModuleID = 'cg_example.c'
source_filename = "cg_example.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@global_ptr = common global i32* null, align 8
@f1.recur = internal global i32 1, align 4

; Function Attrs: noinline nounwind optnone
define i32 @main() #0 {
  %retval = alloca i32, align 4
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %c = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  store i32 1, i32* %a, align 4
  store i32 2, i32* %b, align 4
  store i32 3, i32* %c, align 4
  store i32* %a, i32** @global_ptr, align 8
  %1 = load i32, i32* %a, align 4
  %cmp = icmp eq i32 %1, 1
  br i1 %cmp, label %2, label %7

; <label>:2:                                      ; preds = %0
  %3 = load i32, i32* %b, align 4
  %cmp1 = icmp eq i32 %3, 1
  br i1 %cmp1, label %4, label %5

; <label>:4:                                      ; preds = %2
  store i32 300, i32* %b, align 4
  call void @f1()
  call void @f3()
  store i32 100, i32* %c, align 4
  br label %6

; <label>:5:                                      ; preds = %2
  store i32 300, i32* %b, align 4
  call void @f1()
  store i32 200, i32* %c, align 4
  br label %6

; <label>:6:                                      ; preds = %5, %4
  br label %8

; <label>:7:                                      ; preds = %0
  store i32 300, i32* %c, align 4
  call void @f3()
  store i32 300, i32* %c, align 4
  br label %8

; <label>:8:                                      ; preds = %7, %6
  %9 = load i32, i32* %retval, align 4
  ret i32 %9
}

; Function Attrs: noinline nounwind optnone
define void @f2() #0 {
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  store i32 2, i32* %a, align 4
  store i32 2, i32* %b, align 4
  store i32* %a, i32** @global_ptr, align 8
  %1 = load i32, i32* %a, align 4
  %2 = load i32, i32* %b, align 4
  %cmp = icmp eq i32 %1, %2
  br i1 %cmp, label %3, label %7

; <label>:3:                                      ; preds = %0
  %4 = load i32, i32* %b, align 4
  %cmp1 = icmp eq i32 %4, 3
  br i1 %cmp1, label %5, label %6

; <label>:5:                                      ; preds = %3
  store i32 1, i32* %a, align 4
  br label %6

; <label>:6:                                      ; preds = %5, %3
  store i32 2, i32* %b, align 4
  br label %8

; <label>:7:                                      ; preds = %0
  store i32 1, i32* %a, align 4
  br label %8

; <label>:8:                                      ; preds = %7, %6
  ret void
}

; Function Attrs: noinline nounwind optnone
define void @f1() #0 {
  store i32* @f1.recur, i32** @global_ptr, align 8
  %1 = load i32, i32* @f1.recur, align 4
  %inc = add nsw i32 %1, 1
  store i32 %inc, i32* @f1.recur, align 4
  call void @f2()
  %2 = load i32, i32* @f1.recur, align 4
  %inc1 = add nsw i32 %2, 1
  store i32 %inc1, i32* @f1.recur, align 4
  ret void
}

; Function Attrs: noinline nounwind optnone
define void @f3() #0 {
  %x = alloca i32, align 4
  %y = alloca i32, align 4
  %z = alloca i32, align 4
  store i32 1, i32* %x, align 4
  store i32 2, i32* %y, align 4
  store i32 3, i32* %z, align 4
  store i32* %x, i32** @global_ptr, align 8
  %1 = load i32, i32* %x, align 4
  %cmp = icmp eq i32 %1, 1
  br i1 %cmp, label %2, label %3

; <label>:2:                                      ; preds = %0
  call void @f1()
  store i32 1000, i32* %z, align 4
  br label %8

; <label>:3:                                      ; preds = %0
  %4 = load i32, i32* %y, align 4
  %cmp1 = icmp eq i32 %4, 1
  br i1 %cmp1, label %5, label %6

; <label>:5:                                      ; preds = %3
  call void @f1()
  store i32 2000, i32* %z, align 4
  br label %7

; <label>:6:                                      ; preds = %3
  call void @f1()
  store i32 3000, i32* %z, align 4
  br label %7

; <label>:7:                                      ; preds = %6, %5
  br label %8

; <label>:8:                                      ; preds = %7, %2
  ret void
}

attributes #0 = { noinline nounwind optnone "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-features"="+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 5.0.0 (tags/RELEASE_500/final)"}
