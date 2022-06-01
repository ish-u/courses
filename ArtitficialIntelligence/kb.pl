%% Find the Sum of Two Numbers in Prolog
sum(A, B, S) :-
    S is A+B.

%%  Find the max between X and Y max(X, Y, M)
max(X, Y, M) :-
    (   X>Y,
        M is X, !
    ;   M is Y
    ).

%% Implement Factorial in Prolog Factorial(N, F)
%% base case
factorial(N, false) :-
    N<0, !.
factorial(0, 1) :- !.
factorial(1, 1) :- !.
factorial(N, F) :-
    N1 is N-1,
    factorial(N1, F1),
    F is N*F1.

%% Generate n-th Fibonacci generate_fib(N,T) 
generate_fib(0, 0) :- !.
generate_fib(1, 0) :- !.
generate_fib(2, 1) :- !.
generate_fib(N, T) :-
    N0 is N-2,
    N1 is N-1,
    generate_fib(N0, T0),
    generate_fib(N1, T1),
    T is T0+T1.

%% Find the GCD of two numbers
gcd(X, X, X) :- !.
gcd(X, Y, G) :-
    X<Y,
    Y1 is Y-X,
    gcd(X, Y1, G), !.
gcd(X, Y, G) :-
    X>Y,
    gcd(Y, X, G), !.

%% Find the number raised to power - power(Num,Pow, Ans)
power(_, 0, 1) :- !.
power(Num, 1, Num) :- !.
power(Num, Pow, Ans) :-
    Pow<0,
    Num1 is 1/Num,
    power(Num1, Pow, Ans).
power(Num, Pow, Ans) :-
    Pow1 is Pow-1,
    power(Num, Pow1, Ans1),
    Ans is Num*Ans1.

%% Write a function to multiply two numbers - multiply(N1, N2, R) 
%% base cases
multi(1, N2, N2) :- !.
multi(N1, 1, N1) :- !.
multi(0, _, 0) :- !.
multi(_, 0, 0) :- !.
%% recursive case
multi(N1, N2, R) :-
    N is N2-1,
    multi(N1, N, R1),
    R is N1+R1.
multiply(N1, N2, R) :-
    (   (   N1==0
        ;   N2==0
        ;   N1==1
        ;   N2==1
        ),
        multi(N1, N2, R), !
    ;

    %% case 1 ++
   N1>0,
        N2>0,
        multi(N1, N2, R), !
    ;
    %% case 2 +-
   N1>0,
        N2<0,
        N is -1*N2,
        multi(N1, N, R1),
        R is -1*R1, !
    ;
    %% case 3 -+
   N1<0,
        N2>0,
        N is -1*N1,
        multi(N, N2, R1),
        R is -1*R1, !
    ;
    %% case 4 --
   N1<0,
        N2<0,
        N0 is -1*N1,
        N is -1*N2,
        multi(N0, N, R), !
    ).


% multi(N1, N2, R) :-
%     R is N1*N2.

%% Check if an element is a member of the List memb(X, L)
memb(X, [X|_]) :- !.
memb(X, [_|T]) :-
    memb(X, T).

%% Concatnate two list conc (L1, L2, L3)
conc([], L, L).
conc([H|L1], L2, [H|L3]) :-
    conc(L1, L2, L3).

%% Reverse a List reverse (L, R).
reverse([], []).
reverse([H|L1], R) :-
    reverse(L1, R1),
    conc(R1, [H], R).

%% Check if a List is a palindrome(L)
palindrome(L) :-
    reverse(L, L1),
    L==L1.

%% without reverse
palindrome1([]).
palindrome1([_]).
palindrome1([H|T]) :-
    conc(T1, [H], T),
    palindrome1(T1).    

%% Finding the Sum of the List
sumlist([], 0).
sumlist([H|T], S) :-
    sumlist(T, S1),
    S is H+S1.

%% Find the Length of a List
len([], 0) :- !.
len([_|T], X) :-
    len(T, X1),
    X is 1+X1.


%% Create evenlength(List) and oddlength(List) 
evenLength(L) :-
    len(L, X),
    Y is X mod 2,
    Y==0.
oddLength(L) :-
    len(L, X),
    Y is X mod 2,
    Y==1.

%% without len
even([]) :- !.
even([_|T]) :-
    odd(T).
odd([_]) :- !.
odd([_|T]) :-
    even(T).

%% Find the n-th element in the List
nth_element(1, [H|_], H) :- !.
nth_element(N, [_|T], X) :-
    N1 is N-1,
    nth_element(N1, T, X).

%% Find the max element of the List
maxlist([H], H).
maxlist([H|T], M) :-
    (   maxlist(T, M1),
        M1>H,
        M is M1, !
    ;   M is H
    ).

%% Insert the element in the n-th position
insert_nth(I, 1, L, [I|L]) :- !.
insert_nth(I, N, [H|T], R) :-
    N1 is N-1,
    insert_nth(I, N1, T, R1),
    conc([H], R1, R).


%% Delete the n-th element in the List
delete_nth(1, [_|T], T) :- !.
delete_nth(N, [H|T], R) :-
    N1 is N-1,
    delete_nth(N1, T, R1),
    conc([H], R1, R).

%% Merge two sorted List
merge(L, [], L) :- !.
merge([], L, L) :- !.
merge([H1|L1], [H2|L2], R) :-
    (   H1=<H2,
        merge(L1, [H2|L2], R1),
        conc([H1], R1, R)
    ;   H1>H2,
        merge([H1|L1], L2, R1),
        conc([H2], R1, R)
    ), !.


%% Add an element to the List
add_front(X, L, [X|L]).
add_back(X, L1, L) :-
    conc(L1, [X], L).


%% Divide a List in some parts
dividelist(L1, L2, L) :-
    conc(L1, L2, L).

%% Flatten T,he List
flatten([H|T], L) :-
    flatten(H, L1),
    flatten(T, L2),
    conc(L1, L2, L), !.
flatten([], []).
flatten(H, [H]).


%% Check Order
checkOrder([_]) :- !.
checkOrder([H1, H2|T]) :-
    H1<H2,
    checkOrder([H2|T]).

%% NDFA
final(s3) :- !.


trans(s1, a, s1).
trans(s1, b, s1).
trans(s1, a, s2).
trans(s2, b, s3).
trans(s3, b, s4).

silent(s2, s4).
silent(s3, s1).

accepts(S, []) :-
    final(S).

accepts(S, [X|Rest]) :-
    trans(S, X, S1),
    accepts(S1, Rest).

accepts(S, String) :-
    silent(S, S1),
    accepts(S1, String).

%% 8-Queen Problem
solution([]).

solution([X/Y|Others]) :-
    solution(Others),
    member(Y, [1, 2, 3, 4, 5, 6, 7, 8]),
    noattack(X/Y, Others).

noattack(_, []).

noattack(X/Y, [X1/Y1|Others]) :-
    Y=\=Y1,
    Y1-Y=\=X1-X,
    Y1-Y=\=X-X1,
    noattack(X/Y, Others).

member(X, [X|_]).
member(X, [_|L]) :-
    member(X, L).

% template([1/Y1,2/Y2,3/Y3,4/Y4,5/Y5,6/Y6,7/Y7,8/Y8]).

%% Parser in Prolog
sentence(A, C) :-
    nounPhrase(A, B),
    verbPhrase(B, C).
nounPhrase(A, C) :-
    article(A, B),
    noun(B, C).
nounPhrase(A, B) :-
    noun(A, B).

verbPhrase(A, B) :-
    verb(A, B).
verbPhrase(A, C) :-
    verb(A, B),
    nounPhrase(B, C).
verbPhrase(A, C) :-
    verb(A, B),
    prepositionPhrase(B, C).

prepositionPhrase(A, C) :-
    preposition(A, B),
    nounPhrase(B, C).


preposition([at|X], X).
article([a|X], X).
article([the|X], X).
noun([dog|X], X).
noun([cow|X], X).
noun([moon|X], X).
verb([barked|X], X).
verb([winked|X], X).