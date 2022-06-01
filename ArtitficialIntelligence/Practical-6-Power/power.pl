% Write a Prolog program to implement power (Num,Pow, Ans) : where Num is raised
% to the power Pow to get Ans.
% base case
power(_, 0, Ans) :-
    Ans is 1.
power(Num, 1, Ans) :-
    Ans is Num.
% recursive case
power(Num, Pow, Ans) :-
    Pow>0,
    Pow1 is Pow-1,
    power(Num, Pow1, Ans1),
    Ans is Num*Ans1.
