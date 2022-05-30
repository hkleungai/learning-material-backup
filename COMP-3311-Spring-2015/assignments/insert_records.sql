insert into course values ('Comp3311','database',5);
insert into course values ('Comp2611','computer org',4);
insert into course values ('Comp4311','advanced database',3);
insert into course values ('Comp2011','C++',3);
insert into course values ('Comp2012','OO programming',3);
insert into course values ('Comp1941','Comp Thinking',5);


insert into prof values (1, 'Bond','James','bojames','1');
insert into prof values (2,'Teddy', 'Leung','tleung','1234');
insert into prof values (3,'Billy', 'Joe','bijoe','1234');
insert into prof values (4,'Andy', 'Lau','alau','1234');

insert into prof_phone values (1,11452210);
insert into prof_phone values (1,12452210);
insert into prof_phone values (2,21452210);
insert into prof_phone values (2,22452210);
insert into prof_phone values (3,31452210);
insert into prof_phone values (3,32452210);
insert into prof_phone values (3,33452210);
insert into prof_phone values (4,41452210);


insert into prerequisite values ('Comp3311','Comp2011');
insert into prerequisite values ('Comp3311','Comp2012');
insert into prerequisite values ('Comp3311','Comp2611');
insert into prerequisite values ('Comp4311','Comp3311');

insert into offering values ('Comp3311',222,'Fall2013',322,100,2);
insert into offering values ('Comp3311',223,'Fall2013',322,100,1);
insert into offering values ('Comp3311',224,'Spring2014',322,110,2);
insert into offering values ('Comp3311',230,'Spring2014',322,105,1);

insert into offering values ('Comp4311',100,'Fall2012',322,100,2);
insert into offering values ('Comp2011',501,'Fall2001',415,50,3);
insert into offering values ('Comp2012',502,'Fall2007',412,30,3);
insert into offering values ('Comp2611',701,'Fall2005',120,150,3);


insert into prof_teach values (1,'Comp3311',223);
insert into prof_teach values (1,'Comp3311',230);
insert into prof_teach values (2,'Comp3311',224);
insert into prof_teach values (2,'Comp3311',222);
insert into prof_teach values (2,'Comp3311',223);
insert into prof_teach values (2,'Comp3311',230);
insert into prof_teach values (2,'Comp4311',100);
insert into prof_teach values (3,'Comp2011',501);
insert into prof_teach values (3,'Comp2012',502);
insert into prof_teach values (3,'Comp2611',701);



insert into TA values (101,'Chan','Dongpang',12345678,'Comp3311',223);
insert into TA values (102,'Cheung','siu man',23456781,'Comp3311',224);
insert into TA values (103,'Chan','da man',34567812,'Comp3311',230);
insert into TA values (104,'Chan','wai hung',45678123,'Comp3311',222);
insert into TA values (105,'Lau','Ka wing',56781234,'Comp4311',100);
insert into TA values (106,'Li','Hung wai',67812345,'Comp3311',223);

insert into pref_ta values (1,101);
insert into pref_ta values (2,101);
insert into pref_ta values (3,101);
insert into pref_ta values (4,101);
insert into pref_ta values (1,102);
insert into pref_ta values (2,102);
insert into pref_ta values (3,102);
insert into pref_ta values (4,102);
insert into pref_ta values (3,103);
insert into pref_ta values (4,104);
insert into pref_ta values (4,105);
insert into pref_ta values (4,106);

insert into supervise values (1,101);
insert into supervise values (2,101);
insert into supervise values (1,102);
insert into supervise values (4,103);
insert into supervise values (4,104);
insert into supervise values (2,105);
insert into supervise values (4,106);

insert into pref_offering values (101,'Comp3311',223);
insert into pref_offering values (101,'Comp4311',100);
insert into pref_offering values (102,'Comp3311',223);
insert into pref_offering values (103,'Comp3311',223);
insert into pref_offering values (104,'Comp3311',223);
insert into pref_offering values (105,'Comp3311',223);
insert into pref_offering values (106,'Comp3311',223);



/* additional data for TA */
insert into course values ('Comp4621','Computer networks',5);

insert into prof values (5,'Michael', 'Rabbat','mrabbat','1');
insert into prof values (6,'Peter','Pan','ppan','1');

insert into prerequisite values ('Comp4621','Comp3311');
insert into prerequisite values ('Comp4621','Comp2611');

insert into offering values ('Comp4621',122,'Spring2013',201,150,6);
insert into offering values ('Comp4621',213,'Spring2014',201,125,5);


insert into prof_teach values (5, 'Comp4621',122);
insert into prof_teach values (5, 'Comp4621',213);
insert into prof_teach values (6, 'Comp4621',213);

insert into TA values (107,'Mak','Walter',72445232,'Comp4621',213);

insert into pref_ta values (5,107);
insert into pref_ta values (6,107);

insert into supervise values (1,107);
insert into supervise values (5,107);
insert into supervise values (6,107);

insert into pref_offering values (107,'Comp4621',122);



