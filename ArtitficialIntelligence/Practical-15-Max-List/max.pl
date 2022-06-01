% 15. Write a Prolog program to implement maxlist(L, M) so that M is the maximum
% number in the list.
maxlist([M], M) :- !.
maxlist([H|T], M) :-
    (   maxlist(T, M1),
        M1>=H,
        M is M1, !
    ;   M is H
    ).

