long long exchange(long long *xp, long long y)
{
    long long x = *xp;
    *xp = y;
    return x;
}
/**
movq	(%rcx), %rax .*xp -> x
movq	%rdx, (%rcx) .y -> *xp
ret
*/