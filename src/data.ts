const categorizedCourses: CategorizedCourse[] = [
  {
    category: 'Algorithmic Study',
    courses: [
      {
        code: 'COMP 2711H',
        description: 'Discrete mathematics needed for the study of computer science: sets, functions; propositional logic, predicate logic, rules of inference, proof techniques; pigeonhole principle, basic and generalized permutations and combinations, binomial coefficients, inclusion-exclusion principle; probability theory, Bayes theorem, expectation, variance, random variables, hashing; cryptography and modular arithmetic, Euclid’s division theorem, multiplicative inverse, divisibility, RSA cryptosystem, Chinese remainder theorem; mathematical induction, strong induction and well-ordering property, recursion, recurrence relations; graph representation, isomorphism, connectivity, Euler paths, Hamilton paths, planarity, graph coloring. Gentle introduction to many discrete mathematical concepts that will appear later in more advanced computer science courses.',
        title: 'Honors Discrete Mathematical Tools for Computer Science',
        semesters: ['Fall 2021'],
      }
    ],
  },
  {
    category: 'Big-Data / Database Analysis',
    courses: [
      {
        code: 'COMP 4331',
        description: 'This course will provide an introduction to concepts and techniques in the field of data mining. Materials include an introduction to data warehousing and OLAP, data preprocessing and the techniques used to explore the large quantities of data for the discovery of predictive models and knowledge. The course will include techniques such as nearest neighbor, decision tress, neural networks, Bayesian networks and Naive Bayes, rule-based methods, association analysis and clustering, as well as social networks and data mining applications in business and finance applications, and other emerging data mining subareas. Students learn the materials by attending lectures and implementing and applying different data analysis and mining techniques to large datasets throughout the semester.',
        title: 'Introduction to Data Mining',
        semesters: ['Fall 2021'],
      }
    ],
  },
  {
    category: 'Computer Architecture',
    courses: [
      {
        code: 'COMP 2611',
        description: 'Inner workings of modern digital computer systems and tradeoffs at the hardware-software interface. Topics include: instructions set design, memory systems, input-output systems, interrupts and exceptions, pipelining, performance and cost analysis, assembly language programming, and a survey of advanced architectures.',
        title: 'Computer Organization',
        semesters: ['Spring 2022'],
      },
      {
        code: 'COMP 3511',
        description: 'Principles, purpose and structure of operating systems; processes, threads, and multi-threaded programming; CPU scheduling; synchronization, mutual exclusion; memory management and virtual memory; device management; file systems, security and protection.',
        title: 'Operating System',
        semesters: ['Spring 2022'],
      }
    ],
  },
  {
    category: 'Computer Vision / Graphics',
    courses: [
      {
        code: 'COMP 4451',
        description: 'Computer game development touches on many facets of computer science, including computer graphics, artificial intelligence, algorithms, networking, human-computer interaction, music, and sound. This course will cover all of these aspects, with special emphasis on real-time graphics rendering. Students will get hands-on experience on how to design and implement real-world computer games, which will help improve their skills in programming, teamwork, management, and communication.',
        title: 'Game Programming',
        semesters: ['Spring 2022'],
      }
    ],
  },
  {
    category: 'Internet / Multimedia / Networking',
    courses: [
      {
        code: 'COMP 5622',
        description: 'Advanced principles in computer and communication networking: Internet multicast, overlay and peer-to-peer networks; wireless and mobile computing, multimedia networking, network security, selected topics of current interests: wireless protocols, wireless security, sensor networks, cloud computing, data centers, software-defined networks, network implementation, etc.',
        title: 'Advanced Computer Communications and Networking',
        semesters: ['Spring 2020'],
      }
    ],
  },
  {
    category: 'Introduction to Programming',
    courses: [
      {
        code: 'COMP 102',
        description: 'Introduction to computers and programming. Computer hardware and software. Problem solving. Program design. Procedural abstraction. Debugging and testing. Simple and structured data types. Recursive programming. Introduction to searching and sorting.',
        title: 'Computer and Programming Fundamentals I',
        semesters: ['Summer 1996', 'Spring 1997', 'Spring 1998'],
      },
      {
        code: 'COMP 1021',
        description: 'This course introduces students to the world of Computer Science. Students will experience a range of fun and interesting areas from the world of computing, such as game programming, web programming, user interface design and computer graphics. These will be explored largely by programming in the Python language.',
        title: 'Introduction to Computer Science',
        semesters: ['Spring 2022'],
      },
      {
        code: 'COMP 1022Q',
        description: 'This course is designed to equip students with the fundamental concepts of programming using the VBA programming language, within the context of the Microsoft Excel program. Students will first learn how to use Excel to analyze and present data, and will then learn how to use VBA code to build powerful programs.',
        title: 'Introduction to Computing with Excel VBA',
        semesters: ['Spring 2020'],
      }
    ],
  },
  {
    category: 'Machine Learning',
    courses: [
      {
        code: 'COMP 4211',
        description: 'Fundamentals of machine learning. Concept learning. Evaluating hypotheses. Supervised learning, unsupervised learning and reinforcement learning. Bayesian learning. Ensemble Methods. Deep learning.',
        title: 'Machine Learning',
        semesters: ['Spring 2022'],
      },
      {
        code: 'COMP 5212',
        description: 'Introduction to major learning paradigms and techniques, basic applied statistics and information theory, decision trees, neural networks, Bayesian classification, kernel methods, clustering, density estimation, feature selection and extraction, hidden Markov models, reinforcement learning, case-based learning, model selection and various applications.',
        title: 'Machine Learning',
        semesters: ['Spring 2022'],
      }
    ],
  },
  {
    category: 'Object-oriented Programming',
    courses: [
      {
        code: 'COMP 2011',
        description: 'This course covers programming and data structures using C++. In addition to basic programming concepts such as variables and control statements, students will learn about arrays, pointers, dynamic data allocation, linked lists, stacks, queues, binary trees, recursion, and the basics of object oriented programming.',
        title: 'Programming with C++',
        semesters: ['Fall 2021', 'Spring 2022'],
      },
      {
        code: 'COMP 2012',
        description: 'To learn the fundamental concepts and techniques behind object-oriented programming. They include: abstract data types; creation, initialization, and destruction of objects; class hierarchies; polymorphism, inheritance and dynamic binding; generic programming using templates. To learn the object-oriented view of data structures: linked lists, stacks, queues, binary trees, and algorithms such as searching and hashing.',
        title: 'Object-Oriented Programming and Data Structures',
        semesters: ['Spring 2022'],
      },
      {
        code: 'COMP 2012H',
        description: 'This course is an accelerated and intensive course on concepts and techniques behind object-oriented programming (OOP) and data structures using an OOP language. It covers the major materials of COMP2011 and COMP2012, and its curriculum is designed for students with excellent programming background or substantial programming experience. Topics include: functions; pointers; abstract data types and their class implementation; static and dynamic construction and destruction of objects; data member and member functions; public interface and encapsulation; class hierarchies; polymorphism; inheritance and dynamic binding; standard template library; generic programming using templates; object-oriented view of data structures: linked lists, queues, stacks, trees, and their algorithms such as searching, sorting and hashing.',
        title: 'Honors Object-Oriented Programming and Data Structures',
        semesters: ['Fall 2021'],
      }
    ]
  },
];
