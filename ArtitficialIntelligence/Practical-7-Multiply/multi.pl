% 7. Prolog program to implement multi (N1, N2, R) : where N1 and N2 denotes the
% numbers to be multiplied and R represents the result.
multi(_, 0, R) :-
    R is 0.
multi(0, _, R) :-
    R is 0.
multi(X, 1, R) :-
    R is X.
multi(1, X, R) :-
    R is X.
multi(0, 0, R) :-
    R is 0.
multi(N1, N2, R) :-
    N1>0,
    N2>0,
    N is N2-1,
    multi(N1, N, R1),
    R is N1+R1.