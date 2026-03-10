/**
 * Author: ChatGPT edited from SolveLinearFloat
 * Date: 2026-03-10
 * License: CC0
 * Description: Solves $A * x = b$. If there are multiple solutions, an arbitrary one is returned.
 *  Returns rank, or -1 if no solutions. Data in $A$ and $b$ is lost.
 * Time: O(n^2 m)
 * Status: tested on no game no life
 */
#pragma once

typedef vector<Mod> vm;
int solveLinear(vector<vm>& A, vm& b, vm& x) {
	int n = sz(A), m = sz(x), rank = 0, br, bc;
	if (n) assert(sz(A[0]) == m);
	vi col(m); iota(all(col), 0);
	rep(i,0,n) {
		bool found = 0;
		rep(r,i,n) {
			rep(c,i,m) {
				if (A[r][c] != 0) {
					br = r; bc = c; found = 1;
					break;
				}
			}
			if (found) break;
		}
		if (!found) {
			rep(j,i,n) if (b[j] != 0) return -1;
			break;
		}
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) swap(A[j][i], A[j][bc]);
		Mod bv = Mod(1) / A[i][i];
		rep(j,i+1,n) {
			Mod fac = A[j][i] * bv;
			b[j] = b[j] - fac * b[i];
			rep(k,i+1,m) A[j][k] = A[j][k] - fac * A[i][k];
		}
		rank++;
	}
	x.assign(m, 0);
	for (int i = rank; i--;) {
		b[i] = b[i] / A[i][i];
		x[col[i]] = b[i];
		rep(j,0,i) b[j] = b[j] - A[j][i] * b[i];
	}
	return rank; // (multiple solutions if rank < m)
}
