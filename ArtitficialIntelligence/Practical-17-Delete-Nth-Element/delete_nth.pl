% 17. Write a Prolog program to implement delete_nth (N, L, R) that removes the element
% on Nth position from a list L to generate a list R.
conc([], L, L).
conc([X|L1], L2, [X|L3]) :-
    conc(L1, L2, L3).

delete_nth(1, [_|L], L) :- !.
delete_nth(N, [H|T], R) :-
    N1 is N-1,
    delete_nth(N1, T, R1),
    conc([H], R1, R), !.
