% 10. Write a Prolog program to implement reverse (L, R) where List L is original and List
% R is reversed list
conc([], L, L).
conc([X|L1], L2, [X|L3]) :-
    conc(L1, L2, L3).

reverse([], []).
reverse([H|T], R) :-
    reverse(T, R1),
    conc(R1, [H], R).
