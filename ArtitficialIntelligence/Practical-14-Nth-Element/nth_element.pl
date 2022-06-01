% 14. Write a Prolog program to implement nth_element (N, L, X) where N is the desired
% position, L is a list and X represents the Nth element of L.
nth_element(1, [X|_], X) :- !.
nth_element(N, [_|T], X) :-
    N1 is N-1,
    nth_element(N1, T, X), !.
