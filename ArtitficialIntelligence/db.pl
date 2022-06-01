% facts
% binary relations 
parent(pam, bob).
parent(tom, bob).
parent(tom, liz).
parent(bob, ann).
parent(bob, pat).
parent(pat, jim).

%  unary relations 
male(tom).
male(bob).
male(jim).
female(pam).
female(liz).
female(pat).
female(ann).
f(1, one).
f(s(1), two).
f(s(s(1)), three).
f(s(s(s(X))), N) :-
    f(X, N).

% rules 
% conclusion :- condition 
offspring(Y, X) :-
    parent(X, Y).
mother(X, Y) :-
    parent(X, Y),
    female(X).
father(X, Y) :-
    parent(X, Y),
    male(X).
grandparent(X, Z) :-
    parent(X, Y),
    parent(Y, Z).  
sister(X, Y) :-
    parent(Z, X),
    parent(Z, Y),
    female(X),
    X\=Y.
hasChild(X) :-
    parent(X, _).
happy(X) :-
    hasChild(X).
hasTwoChildren(X) :-
    parent(X, Y),
    sister(_, Y).
grandchild(X, Z) :-
    parent(Z, Y),
    parent(Y, X). 
aunt(X, Y) :-
    parent(Z, Y),
    sister(X, Z).


%  recursive relation 
predecessor(X, Z) :-
    parent(X, Z).
predecessor(X, Z) :-
    parent(X, Y),
    predecessor(Y, Z).

sum(X, Y) :-
    S is X+Y,
    write("SUM : "),
    write(S).

% point(X,Y).
% seg(P1,P2).
% vertical(seg(point(X,Y),point(X,Y1))).
% horizontal(seg(point(X1,Y),point(X,Y))).

% LIST

% membership
% member(X, [H|T]) :-
%     (   X is H
%     ;   member(X, T)
%     ).
member(X, [X|_]).
member(X, [_|T]) :-
    member(X, T).

% concatenation
conc([], L, L) :- !.
conc([X|L1], L2, [X|L3]) :-
    conc(L1, L2, L3).

% write list
writeList([]) :- !.
writeList([H|T]) :-
    write(H),
    write('\n'),
    writeList(T).

% write list reverse
writeListRev([]).
writeListRev([H|T]) :-
    writeListRev(T),
    write(H),
    write('\n').

% sum list
sumList([], 0).
sumList([H|T], S) :-
    sumList(T, S1),
    write(S1),
    write('\n'),
    S is H+S1.

% reverse list
% reverseList([], _).
% reverseList([H|T], [L]) :-
%     reverseList(T, [L|H]).

% last element
% last(Item,List):-
%     conc(_,[Item],List).
last(X, [_, X]) :- !.
last(Item, [_|T]) :-
    last(Item, T).

% delete last three
delete_last(L, L1) :-
    conc(L1, [_, _, _], L).

% delete first three
delete_first(L, L1) :-
    conc([_, _, _], L1, L).

% delete last element
delete_last_element(L, L1) :-
    conc(L1, [_], L).


% add an element to list
% add(X, L, [X|L]).
add(X, L, [X|L]).

% add an element to the back of the List
add_last(X, L, L1) :-
    conc([X], L, L1).

% delete an element from list
delete(X, [X], []).
delete(X, [X|L], L).
delete(X, [Y|L], [Y|L1]) :-
    delete(X, L, L1).
% delete(X, [X|_]).
% delete(X, [_|L]) :-
%     delete(X, L),
%     write(L).

% delete as insert
insertUsingDelete(X, L, BL) :-
    delete(X, BL, L).

% sublist
subList(S, L) :-
    conc(_, L2, L),
    conc(S, _, L2).

% subset([], []).    
% subset([H|T], [H|S]) :-
%     subset(T, S).
% subset(L, [_|S]) :-
%     subset(L, S).

% permutation
insert(X, L, L1) :-
    delete(X, L1, L).

permutation([], []).
permutation([X|L], P) :-
    permutation(L, L1),
    insert(X, L1, P).

%length of a list
lengthList([], 0).
lengthList([_|L], Length) :-
    lengthList(L, Length1),
    Length is Length1+1.

% check whether the list is odd or even length
evenLength(L) :-
    lengthList(L, X),
    Y is X mod 2,
    Y==0.
    
oddLength(L) :-
    lengthList(L, X),
    Y is X mod 2,
    Y==1.

% reverse list
% reverseList([H|T], Reverse) :-
%     reverseList(T, Reverse1),
%     insert(H, Reverse1, Reverse).
reverseList([], []).
reverseList([H|T], Reverse) :-
    reverseList(T, Reverse1),
    conc(Reverse1, [H], Reverse).


% pallindrome
pallindrome(L1) :-
    reverseList(L1, L2),
    L1=L2.

% shift
shift([H|T], L2) :-
    conc(T, [H], L2).

% translate
means(0, zero).
means(1, one).
means(2, two).
means(3, three).
means(4, four).
means(5, five).
means(6, six).
means(7, seven).
means(8, eight).
means(9, eight).
translate([], []).
translate([H|T], L) :-
    translate(T, L1),
    means(H, A),
    conc([A], L1, L).


%% subste
subset([], []).
subset([First|Rest], [First|Sub]) :-
    subset(Rest, Sub).

subset([_|Rest], Sub) :-
    subset(Rest, Sub).

dividelist([], [], []).
dividelist([X], [X], []).
dividelist([X, Y|List], [X|List1], [Y|List2]) :-
    dividelist(List, List1, List2).

flat([H|T], F) :-
    flat(H, L1),
    flat(T, L2),
    conc(L1, L2, F).
flat([], []).
flat(X, [X]).


% n-th element
nth_element(1, [X|_], X).
nth_element(N, [_|T], X) :-
    N1 is N-1,
    nth_element(N1, T, X).

% max element
% maxlist([], 0).
% maxlist([H|T], M) :-
    % (   maxlist(T, M1),
    %     M is M1
    % ;   M1<H
    % ->  M is H,
    %     write(M)
    % ).
    % write(M1),
    % (   H<M1
    % ->  M is M1
    % ).
max(X, Y, M) :-
    (   X>=Y,
        M is X, !
    ;   M is Y
    ).
maxlist([M], M).
maxlist([H|T], M) :-
    (   maxlist(T, M1),
        M1>=H,
        M is M1, !
    ;   M is H
    ).


% sumlist
sumlist([], 0).
sumlist([H|T], S) :-
    sumList(T, S1),
    S is S1+H.
    

% ordered List
checkOrder((_| [H, T])) :-
    H>T.
% ordered([H|T]):-
%     checkOrder()

% insert n-th element
insert_nth(H, 1, L, [H|L]).
insert_nth(I, N, [H|T], R) :-
    N1 is N-1,
    insert_nth(I, N1, T, R1),
    conc([H], R1, R), !.

% delete n-th element
delete_nth(1, [_|L], L).
delete_nth(N, [H|T], R) :-
    N1 is N-1,
    delete_nth(N1, T, R1),
    conc([H], R1, R), !.


sortAndMerge(L1, L2, L) :-
    sort(L1, L1_),
    sort(L2, L2_),
    merge(L1_, L2_, L).
    

% merge list
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


% base case
generate_fib(0, 1) :- !.
generate_fib(1, 1) :- !.
% recursive case
generate_fib(N, T) :-
    N>0,
    N>1,
    N1 is N-1,
    N0 is N-2,
    generate_fib(N0, T0),
    generate_fib(N1, T1),
    T is T0+T1.
print_fib(N) :-
    N> -1,
    generate_fib(N, T),
    write(T),
    write("\t"),
    N1 is N-1,
    print_fib(N1).

getFib(0, []).
getFib(N, L) :-
    N1 is N-1,
    getFib(N1, L1),
    generate_fib(N1, X),
    conc(L1, [X], L), !.
