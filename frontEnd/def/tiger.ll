; ModuleID = 'Tiger_code.tig'
source_filename = "Tiger_code.tig"

define void @foo() {
entry:
  %x1 = alloca double
  %y = alloca double
  %x = alloca double
  %0 = load double, double* %x
  store double %0, double* %x
  %1 = load double, double* %y
  store double %1, double* %y
  %2 = load double, double* %x1
  store double %2, double* %x1
  %addtmp = fadd void <badref>, float 5.000000e+00
  %subtmp = fsub void %addtmp, float 4.000000e+00
  ret void
}

define void @bar() {
entry:
  %z1 = alloca double
  %z = alloca double
  %0 = load double, double* %z
  store double %0, double* %z
  %1 = load double, double* %z1
  store double %1, double* %z1
  %multmp = fmul void <badref>, <badref>
  %subtmp = fsub void %multmp, float 4.000000e+00
  ret void
}

define void @bazz() {
entry:
  %yy = alloca double
  %0 = load double, double* %yy
  store double %0, double* %yy
  %addtmp = fadd void <badref>, float 2.000000e+00
  ret void
}