desc course;
desc prof;
desc prof_phone;
desc prerequisite;
desc offering;
desc prof_teach;
desc TA;
desc pref_offering;
desc supervise;
desc pref_TA;

SELECT column_name FROM all_cons_columns WHERE constraint_name = (
  SELECT constraint_name FROM user_constraints 
  WHERE UPPER(table_name) = UPPER('course') AND CONSTRAINT_TYPE = 'P'
);

SELECT column_name FROM all_cons_columns WHERE constraint_name = (
  SELECT constraint_name FROM user_constraints 
  WHERE UPPER(table_name) = UPPER('prof') AND CONSTRAINT_TYPE = 'P'
);

SELECT column_name FROM all_cons_columns WHERE constraint_name = (
  SELECT constraint_name FROM user_constraints 
  WHERE UPPER(table_name) = UPPER('prof_phone') AND CONSTRAINT_TYPE = 'P'
);

SELECT column_name FROM all_cons_columns WHERE constraint_name = (
  SELECT constraint_name FROM user_constraints 
  WHERE UPPER(table_name) = UPPER('prerequisite') AND CONSTRAINT_TYPE = 'P'
);

SELECT column_name FROM all_cons_columns WHERE constraint_name = (
  SELECT constraint_name FROM user_constraints 
  WHERE UPPER(table_name) = UPPER('offering') AND CONSTRAINT_TYPE = 'P'
);

SELECT column_name FROM all_cons_columns WHERE constraint_name = (
  SELECT constraint_name FROM user_constraints 
  WHERE UPPER(table_name) = UPPER('prof_teach') AND CONSTRAINT_TYPE = 'P'
);

SELECT column_name FROM all_cons_columns WHERE constraint_name = (
  SELECT constraint_name FROM user_constraints 
  WHERE UPPER(table_name) = UPPER('TA') AND CONSTRAINT_TYPE = 'P'
);

SELECT column_name FROM all_cons_columns WHERE constraint_name = (
  SELECT constraint_name FROM user_constraints 
  WHERE UPPER(table_name) = UPPER('pref_offering') AND CONSTRAINT_TYPE = 'P'
);

SELECT column_name FROM all_cons_columns WHERE constraint_name = (
  SELECT constraint_name FROM user_constraints 
  WHERE UPPER(table_name) = UPPER('supervise') AND CONSTRAINT_TYPE = 'P'
);

SELECT column_name FROM all_cons_columns WHERE constraint_name = (
  SELECT constraint_name FROM user_constraints 
  WHERE UPPER(table_name) = UPPER('pref_TA') AND CONSTRAINT_TYPE = 'P'
);

SELECT UC.TABLE_NAME,
          UC.R_CONSTRAINT_NAME,
          UCC.TABLE_NAME,
          UCC.COLUMN_NAME
     FROM USER_CONSTRAINTS  UC,
          USER_CONS_COLUMNS UCC
    WHERE UC.R_CONSTRAINT_NAME = UCC.CONSTRAINT_NAME
      AND uc.constraint_type = 'R'
    ORDER BY UC.TABLE_NAME,
             UC.R_CONSTRAINT_NAME,
             UCC.TABLE_NAME,
             UCC.COLUMN_NAME;