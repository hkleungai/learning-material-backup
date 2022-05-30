CREATE TABLE Course
(course_ID varchar2(8),
course_name varchar2(80),
credits number(3),
PRIMARY KEY (course_ID));

CREATE TABLE Prof
(staff_ID number(8),
last_name varchar2(80),
first_name varchar2(80),
PRIMARY KEY (staff_ID));

CREATE TABLE Offering
(course_ID varchar2(8),
offering_no number(8),
YearSemester varchar2(10),
classroom number(5),
no_of_stds number(5),
staff_ID number(8) NOT NULL,
FOREIGN KEY (course_ID) REFERENCES Course(course_ID),
FOREIGN KEY (staff_ID) REFERENCES Prof(staff_ID),
PRIMARY KEY (course_ID, offering_no));

CREATE TABLE TA
(student_ID number(8),
last_name varchar2(80),
first_name varchar2(80),
phone number(8),
course_ID varchar2(8) NOT NULL,
offering_no number(8) NOT NULL,
FOREIGN KEY (course_ID,offering_no) REFERENCES Offering(course_ID,offering_no),
PRIMARY KEY (student_ID));


CREATE TABLE Prof_phone
(staff_ID number(8),
phone_number number(8),
PRIMARY KEY (staff_ID, phone_number),
FOREIGN KEY (staff_ID) REFERENCES Prof(staff_ID));

CREATE TABLE Prerequisite
(main_course_ID varchar2(8),
prereq_course_ID varchar2(8),
FOREIGN KEY (main_course_ID) REFERENCES Course(course_ID),
FOREIGN KEY (prereq_course_ID) REFERENCES Course(course_ID),
PRIMARY KEY (main_course_ID, prereq_course_ID));

CREATE TABLE Prof_teach
(staff_ID number(8),
course_ID varchar2(8),
offering_no number(8),
FOREIGN KEY (staff_ID) REFERENCES Prof(staff_ID),
FOREIGN KEY (course_ID,offering_no) REFERENCES Offering(course_ID,offering_no),
PRIMARY KEY (staff_ID, course_ID, offering_no));

CREATE TABLE Pref_TA
(staff_ID number(8),
student_ID number(8),
FOREIGN KEY (staff_ID) REFERENCES Prof(staff_ID),
FOREIGN KEY (student_ID) REFERENCES TA(student_ID),
PRIMARY KEY (staff_ID, student_ID));

CREATE TABLE Supervise
(staff_ID number(8),
student_ID number(8),
FOREIGN KEY (staff_ID) REFERENCES Prof(staff_ID),
FOREIGN KEY (student_ID) REFERENCES TA(student_ID),
PRIMARY KEY (staff_ID, student_ID));

CREATE TABLE Pref_offering
(student_ID number(8),
course_ID varchar2(8),
offering_no number(8),
FOREIGN KEY (student_ID) REFERENCES TA(student_ID),
FOREIGN KEY (course_ID,offering_no) REFERENCES Offering(course_ID,offering_no),
PRIMARY KEY (student_ID, course_ID, offering_no));

insert into course values ('Comp2011',  'Introduction to OOP', 4);
insert into course values ('Comp3311',  'Database Management Systems', 3);
insert into course values ('Comp4311',  'Database Architecture and Implementation', 3);
insert into course values ('ELEC3100',  'Signal Processing and Communications', 4);
insert into course values ('MATH3425',  'Stochastic Modeling', 3);
insert into course values ('HUMA2104',  'Introduction to Music Theory', 3);

insert into Prof values (1001,  'AAA', 'ZZZ');
insert into Prof values (1002,  'BBB', 'YYY');
insert into Prof values (1003,  'CCC', 'XXX');
insert into Prof values (1004,  'DDD', 'QQQ');
insert into Prof values (1005,  'EEE', 'PPP');
insert into Prof values (1006,  'FFF', 'OOO');

insert into Offering values ('Comp3311',9001,'2010S','111','100',1001);
insert into Offering values ('Comp3311',9002,'2011S','111','100',1002);
insert into Offering values ('Comp3311',9003,'2012S','111','100',1001);
insert into Offering values ('Comp4311',9004,'2010S','111','100',1002);
insert into Offering values ('Comp4311',9005,'2011S','111','100',1001);
insert into Offering values ('Comp4311',9006,'2012S','111','100',1001);
insert into Offering values ('Comp2011',9007,'2012S','111','100',1003);
insert into Offering values ('MATH3425',9008,'2012S','111','100',1004);

insert into TA values ('00000001','ta1','fn1','111','Comp3311',9001);
insert into TA values ('00000002','ta2','fn2','111','Comp3311',9001);
insert into TA values ('00000003','ta3','fn3','111','Comp3311',9002);
insert into TA values ('00000004','ta4','fn4','111','Comp3311',9002);
insert into TA values ('00000005','ta5','fn5','111','Comp3311',9003);

insert into Prof_teach values (1001,'Comp3311',9001);
insert into Prof_teach values (1001,'Comp3311',9002);
insert into Prof_teach values (1001,'Comp3311',9003);
insert into Prof_teach values (1002,'Comp3311',9003);
insert into Prof_teach values (1002,'Comp4311',9004);
insert into Prof_teach values (1003,'Comp4311',9004);
insert into Prof_teach values (1003,'Comp4311',9005);
insert into Prof_teach values (1004,'Comp2011',9007);
insert into Prof_teach values (1004,'MATH3425',9008);

insert into Pref_TA values (1001,'00000001');
insert into Pref_TA values (1002,'00000001');
insert into Pref_TA values (1003,'00000002');
insert into Pref_TA values (1004,'00000002');
insert into Pref_TA values (1005,'00000003');
insert into Pref_TA values (1006,'00000004');
insert into Pref_TA values (1001,'00000005');

insert into Prerequisite values ('Comp3311','MATH3425');
insert into Prerequisite values ('Comp3311','Comp2011');
insert into Prerequisite values ('Comp4311','Comp3311');

