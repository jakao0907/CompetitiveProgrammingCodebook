// Suppose A is a (n x n) real symmetric matrix
#define _USE_MATH_DEFINES
#define _EPSILON 1e-9
#define Matrix vector<vector<double, double> >
void update_P_mtx(Matrix &P, int p, int q, double c, double s) { // O(N)
    int rows = P.getShape().first;
    vector<double> Qp(rows, 0.0);
    vector<double> Qq(rows, 0.0);
    for(int k = 0; k < rows; k++) {
        Qp[k] =  c*P[k][p] + s*P[k][q];
        Qq[k] = -s*P[k][p] + c*P[k][q];
    }
    for(int k = 0; k < rows; k++) {
        P[k][p] = Qp[k];
        P[k][q] = Qq[k];
    }
}
void update_A_mtx(Matrix &A, int p, int q, double c, double s) { // O(N)
    int n = A.getShape().first;
    vector<double> Bp(n, 0.0);
    vector<double> Bq(n, 0.0);
    Bp[p] = c*c*A[p][p] + 2.0*s*c*A[p][q] + s*s*A[q][q];
    Bq[q] = s*s*A[p][p] - 2.0*s*c*A[p][q] + c*c*A[q][q];
    for(int r = 0; r < n; r++) {
        if (r != p && r != q) {
            Bp[r] =  c*A[r][p] + s*A[r][q];
            Bq[r] = -s*A[r][p] + c*A[r][q];
        }
    }
    for(int k = 0; k < n; k++) {
        A[p][k] = A[k][p] = Bp[k];
        A[q][k] = A[k][q] = Bq[k];
    }
    A[p][q] = A[q][p] = 0.0;
}
double max_off_diag_entry(Matrix &A, int &p, int &q) { // (O(N^2)
    // Suppose A is a symmetric matrix
    int rows = A.getShape().first, cols = A.getShape().second;
    double max_value = -__DBL_MAX__;

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if (i != j && fabs(A[i][j]) > max_value) {
                max_value = fabs(A[i][j]);
                p = i;
                q = j;
    }}}
    return max_value;
}
pair<Matrix, Matrix> jacobian(Matrix m) { // O(k*(2N + N^2))
    Matrix A(m);
    int rows = A.getShape().first, cols = A.getShape().first, p, q, iterations = 0;
    Matrix P = Matrix::identity(rows, cols);
    double Apq = max_off_diag_entry(A, p, q);
    
    while(fabs(Apq) > _EPSILON){
        iterations++;
        double theta = atan2((A[p][q] * 2.0), (A[p][p] - A[q][q]))/2.0;
        double c = cos(theta);
        double s = sin(theta);
        update_P_mtx(P, p, q, c, s); // P = P*R;
        update_A_mtx(A, p, q, c, s); // B = R.T()*A*R;
        Apq = max_off_diag_entry(A, p, q);
    }
    return make_pair(A, P);
}
