% 1. Write a prolog program to calculate the sum of two numbers.
sum(X, Y) :-
    S is X+Y,
    write("SUM : "),
    write(S).