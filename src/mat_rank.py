import numpy as np
def mat_rank(matr):
    m=np.array(matr)
    #stand for the current principle elem col
    c=0
    #stand for current start row
    r=0
    while (1):
        #stop criteria
        if c==m.shape[1]:
            break
        if r==m.shape[0]:
            break
        #found current row such that col c is nonzero
        found=False
        for i in range(r,m.shape[0]):
            if abs(m[i][c])>1e-6:
                found=True
                if i!=r:
                    p=m[i]
                    m[i]=m[r]
                    m[r]=p
                break
        if found:
            for i in range(r+1,m.shape[0]):
                m[i]=m[i]-m[i][c]/m[r][c]*m[r]
            r=r+1
        c=c+1
    return m

a = np.matrix('1 2 7; 3 4 8; 5 6 9')
print(a.shape)
print(mat_rank(a))