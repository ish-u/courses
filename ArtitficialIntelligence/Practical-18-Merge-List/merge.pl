% 18. Write a program in PROLOG to implement merge (L1, L2, L3) where L1 is first
% ordered list and L2 is second ordered list and L3 represents the merged list.
conc([], L, L).
conc([X|L1], L2, [X|L3]) :-
    conc(L1, L2, L3).

merge([], [], []) :- !.
merge([], L, L) :- !.
merge(L, [], L) :- !.
merge([H1|T1], [H2|T2], L) :-
    (   H1=<H2,
        merge(T1, [H2|T2], L1),
        conc([H1], L1, L), !
    ;   merge([H1|T1], T2, L2),
        conc([H2], L2, L)
    ).
