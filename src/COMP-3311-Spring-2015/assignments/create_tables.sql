Create table course (
course_ID varchar2(8) primary key,
course_name varchar2(80),
credits number(3)
);

 
Create table prof (
staff_ID number(8) primary key,
last_name varchar2(80),
first_name varchar2(80),
user_name varchar2(20),
password varchar2(10)
);

Create table prof_phone (
staff_ID number(8) references prof(staff_ID),
phone_number number(8) unique,
primary key (staff_ID, phone_number)
);

Create table prerequisite (
main_course_ID varchar2(8) references course(course_ID),
prereq_course_ID varchar2(8) references course(course_ID),
primary key (main_course_ID, prereq_course_ID)
);

/* offering must be created before those tables that references (course_ID,offering_no)*/
Create table offering (
course_ID varchar2(8) references course(course_ID),
offering_no number(8),
YearSemester varchar2(10),
classroom number(5),
no_of_stds number(5),
staff_ID number(8) NOT NULL references prof(staff_ID),
primary key (course_ID, offering_no)
);

Create table prof_teach (
staff_ID number(8) references prof(staff_ID),
course_ID  varchar2(8),
offering_no  number(8),
foreign key (course_ID,offering_no) references offering(course_ID,offering_no),
primary key (staff_ID, course_ID,offering_no)
);


/* TA must be created before those tables that references (student_ID)*/

Create table TA (
student_ID  number(8)  primary key,
last_name varchar2(80),
first_name varchar2(80),
phone number(8),
course_ID varchar2(8) NOT NULL,
offering_no number(8) NOT NULL,
      foreign key (course_ID,offering_no) references offering(course_ID,offering_no)
);
 
Create table pref_TA (
staff_ID number(8) references prof(staff_ID),
student_ID number(8) references TA(student_ID),
primary key (staff_ID, student_ID)
);

Create table supervise (
staff_ID number(8) references prof(staff_ID),
student_ID number(8) references TA(student_ID),
primary key (staff_ID, student_ID)
);

Create table pref_offering (
student_ID number(8) references TA(student_ID),
course_ID varchar2(8),
offering_no number(8),
foreign key (course_ID,offering_no) references offering(course_ID,offering_no), 
primary key (student_ID, course_ID, offering_no)
);


