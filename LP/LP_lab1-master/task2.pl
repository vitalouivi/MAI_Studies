%������ four.pl
%������� 3
group(102,['������','����������','���������','������','������','�����������','����������������','������','���������������']).
group(101,['����������','�������','�����','����������','�����������������']).
group(104,['������','����������','�����','����','���������������','����������']).
group(103,['��������','��������','������������','�����������','���������������','����������','������������','�����������']).

subject('���������� ����������������',[grade('������',4),grade('����������',2),grade('������',5),grade('����������',5),grade('����������',5),grade('�������',2),grade('��������',4),grade('���������',4),grade('��������',3),grade('������������',4),grade('�����������',4),grade('�����',2),grade('���������������',5),grade('�����',3),grade('����',5),grade('����������',5),grade('������',5),grade('���������������',4),grade('����������',5),grade('������',4),grade('�����������',4),grade('������������',5),grade('�����������������',5),grade('����������������',5),grade('����������',3),grade('������',5),grade('�����������',5),grade('���������������',3)]).
subject('�������������� ������',[grade('������',2),grade('����������',4),grade('������',4),grade('����������',4),grade('����������',4),grade('�������',5),grade('��������',4),grade('���������',5),grade('��������',4),grade('������������',5),grade('�����������',3),grade('�����',4),grade('���������������',3),grade('�����',5),grade('����',4),grade('����������',3),grade('������',4),grade('���������������',4),grade('����������',5),grade('������',3),grade('�����������',4),grade('������������',4),grade('�����������������',5),grade('����������������',4),grade('����������',3),grade('������',5),grade('�����������',4),grade('���������������',5)]).
subject('�������������� ����������������',[grade('������',3),grade('����������',5),grade('������',4),grade('����������',3),grade('����������',3),grade('�������',3),grade('��������',4),grade('���������',5),grade('��������',5),grade('������������',5),grade('�����������',4),grade('�����',5),grade('���������������',5),grade('�����',5),grade('����',4),grade('����������',5),grade('������',3),grade('���������������',3),grade('����������',4),grade('������',4),grade('�����������',3),grade('������������',4),grade('�����������������',4),grade('����������������',5),grade('����������',5),grade('������',4),grade('�����������',4),grade('���������������',4)]).
subject('�����������',[grade('������',4),grade('����������',3),grade('������',3),grade('����������',4),grade('����������',3),grade('�������',4),grade('��������',4),grade('���������',4),grade('��������',3),grade('������������',2),grade('�����������',4),grade('�����',5),grade('���������������',4),grade('�����',5),grade('����',3),grade('����������',4),grade('������',5),grade('���������������',5),grade('����������',4),grade('������',4),grade('�����������',3),grade('������������',5),grade('�����������������',3),grade('����������������',2),grade('����������',4),grade('������',5),grade('�����������',4),grade('���������������',4)]).
subject('���������� ����',[grade('������',4),grade('����������',5),grade('������',3),grade('����������',4),grade('����������',4),grade('�������',5),grade('��������',3),grade('���������',5),grade('��������',5),grade('������������',5),grade('�����������',4),grade('�����',4),grade('���������������',3),grade('�����',5),grade('����',4),grade('����������',3),grade('������',4),grade('���������������',4),grade('����������',2),grade('������',4),grade('�����������',4),grade('������������',5),grade('�����������������',5),grade('����������������',5),grade('����������',3),grade('������',2),grade('�����������',4),grade('���������������',4)]).
subject('����������',[grade('������',5),grade('����������',3),grade('������',3),grade('����������',3),grade('����������',5),grade('�������',3),grade('��������',5),grade('���������',4),grade('��������',5),grade('������������',5),grade('�����������',3),grade('�����',4),grade('���������������',4),grade('�����',4),grade('����',4),grade('����������',2),grade('������',3),grade('���������������',2),grade('����������',4),grade('������',3),grade('�����������',3),grade('������������',5),grade('�����������������',4),grade('����������������',5),grade('����������',5),grade('������',3),grade('�����������',5),grade('���������������',4)]).


%������� ���� ��������
%���������� ���������� ������ �������� Student ������ �� ��������� ������
studsearch([], _, 0).
studsearch([grade(X, Y)|_], Student, M) :-X == Student, !, M is Y.
studsearch([_|T], Student, N) :-studsearch(T, Student, N).

%���������� ��� ������ ��������
%(������� ��������, ������)
marks_for_exams(Student, X) :-subject(_, Y), studsearch(Y, Student, X).

average_mark(Student, S) :-bagof(X, marks_for_exams(Student, X), L), sum_list(L, SL), length(L, LL), S is SL / LL.

%����� �� �������� � ��������
fcheck(Student, Sub) :-subject(Sub, Y), studsearch(Y, Student, M), M > 2.

%- ��� ������� ��������, ����� ���������� �� ������� ���������

fcount([], 0).
fcount([grade(_, Y)|T], C) :-Y < 3, !, fcount(T, N), C is N + 1.

fcount([_|T], N) :-fcount(T, N).
%(�������, ����������)
fail(Sub, X) :-subject(Sub, L), fcount(L, X).

%- ��� ������ ������, ����� �������� (���������) � ������������ ������� ������

%������� ������
avg([H|_], X) :-average_mark(H, X).

avg([_|T], X) :-avg(T, X).

%����������� ���������� ������� ������
check_best([], _).	
check_best([H|T], Max) :-average_mark(H, A), A =:= Max, !, check_best(T, Max), write(H), nl.
check_best([_|T], Max) :-check_best(T, Max).

%���������� � ������ ��������� � ���������� �������
group_best(N) :-group(N, Y), bagof(M, avg(Y, M), L), max_list(L, Max), check_best(Y, Max).

