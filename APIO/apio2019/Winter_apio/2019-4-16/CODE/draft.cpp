for (int c=1; c<=ALPHA; ++c) {
		for (int j=1; j<=m; ++j)
			Hs[c][j] = Hs[c][j-1] * BASE + (s[j]==c ? 1 : 2);
	}