func maxProduct(n int) int {
    f:=0
    s:=0
    for n>0 {
        x:=n%10
        if x>f {
            s=f
            f=x
        } else if x>s {
            s=x
        }
        n/=10
    }
    return f*s
}