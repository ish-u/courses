% 16. Write a prolog program to implement insert_nth (I, N, L, R) that inserts an item I into
% Nth position of list L to generate a list R.
conc([], L, L).
conc([X|L1], L2, [X|L3]) :-
    conc(L1, L2, L3).

insert_nth(H, 1, L, [H|L]) :- !.
insert_nth(I, N, [H|T], R) :-
    N1 is N-1,
    insert_nth(I, N1, T, R1),
    conc([H], R1, R), !.
