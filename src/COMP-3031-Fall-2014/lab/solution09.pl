/*Q1.*/
?-member(Y,[[1,2],[3,4]]),member(X,Y),!.   % returns X=1 only
?-member(Y,[[1,2],[3,4]]),!,member(X,Y).   % returns X=1, X=2 successively



/*Q2.*/
/* file: mymerge.pl*/
mymerge(L1, [], L1) :- !. 
mymerge([], L2, L2). 
mymerge([X1 | L1], [X2 | L2], [X1 | L]) :-  X1 < X2, !, mymerge(L1, [X2 | L2], L). 
mymerge([X1 | L1], [X2 | L2], [X2 | L]) :-  mymerge([X1 | L1], L2, L). 


/*Q3.*/
/*First question:*/

/*Yes, modify it into:*/

q(a).
p(b).
p(X):-!,q(X).

