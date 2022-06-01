% 13. Write a Prolog program to implement two predicates evenlength(List) and
% oddlength(List) so that they are true if their argument is a list of even or odd length
% respectively.

%length of a list
lengthList([], 0).
lengthList([_|L], Length) :-
    lengthList(L, Length1),
    Length is Length1+1.

% check whether the list is odd or even length
evenlength(L) :-
    lengthList(L, X),
    Y is X mod 2,
    Y==0.
    
oddlength(L) :-
    lengthList(L, X),
    Y is X mod 2,
    Y==1.

