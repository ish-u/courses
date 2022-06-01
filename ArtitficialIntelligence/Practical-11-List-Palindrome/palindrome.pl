% 11. Write a program in PROLOG to implement palindrome (L) which checks whether a
% list L is a palindrome or not
conc([], L, L).
conc([X|L1], L2, [X|L3]) :-
    conc(L1, L2, L3).

reverse([], []).
reverse([H|T], R) :-
    reverse(T, R1),
    conc(R1, [H], R).


palindrome(L1) :-
    reverse(L1, L2),
    L1=L2.
