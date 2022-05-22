const FETCHED_COURSES = {
    'COMP 001': {
        title: 'Academic and Professional Development I',
        description: 'A compulsory one-year course forstudents of the Department of Computer Science and Engineering. This course is designed to provide academic advising to students and to develop their communication skills in interacting with technical and non-technical audiences. Graded P or F.'
    },
    'COMP 002': {
        title: 'Academic and Professional Development II',
        description: 'Continuation of COMP 001. A compulsory, one year course for students of the Department of Computer Science and Engineering. Graded P or F.'
    },
    'COMP 003': {
        title: 'Academic and Professional Development III',
        description: 'Continuation of COMP 002. A compulsory, one year course for students of the Department of Computer Science and Engineering. Graded P or F.'
    },
    'COMP 099': {
        title: 'Industrial Training',
        description: 'For students of the Department of Computer Science and Engineering only. A practical training course for a period of three weeks. Topics include Linux system administration, Linux network administration, managing and maintaining a Windows server environment, and safety. Graded P or F.'
    },
    'COMP 101': {
        title: 'Exploring Multimedia and Internet Computing',
        description: 'Interesting and useful things you can do on the computer, but take time to learn.  Introduction to multimedia and internet computing tools.  Internet, e-mail, WWW, webpage design, computer animation, spreadsheet charts/figures, presentations with graphics and animations, etc.  Business, security, accessibility, and relevant IP right issues in the use of computers.'
    },
    'COMP 102': {
        title: 'Computer and Programming Fundamentals I',
        description: 'Introduction to computers and programming. Computer hardware and software. Problem solving. Program design. Procedural abstraction. Debugging and testing. Simple and structured data types. Recursive programming. Introduction to searching and sorting.'
    },
    'COMP 103': {
        title: 'Computer and Programming Fundamentals II',
        description: 'Programming techniques and introduction to object-oriented programming. Classes and objects. Data encapsulation and information hiding. Abstract data types. Pointers and linked data structures. Recursive data structures. Searching and sorting.'
    },
    'COMP 104': {
        title: 'Programming Fundamentals and Methodology',
        description: 'Structured programming and introduction to object-oriented programming. Problem solving. Program design. Procedural abstraction. Debugging and testing. Classes, objects, and dynamic objects. Abstract data types. Linked data structures. Searching, sorting, and recursive programming.'
    },
    'COMP 104H': {
        title: 'Programming Fundamentals and Methodology (Honors Study Track)',
        description: 'Structured programming and introduction to object-oriented programming.  Problem solving.  Program design.  Procedural abstraction.  Debugging and testing.  Classes, objects, and dynamic objects.  Abstract data types.  Linked data structures.  Searching, sorting, and recursive programming.  This is a half-semester course.  Enrollment in the course requires approval of the course instructor.'
    },
    'COMP 105': {
        title: 'Exploring Music: Music Technology and Creation',
        description: 'An introductory and interdisciplinary approach to learning music by designing and building simple musical instruments.  This course will combine music science, software tools and creativity to introduce students to the fundamentals of music with their active participation.  Students will learn about instruments from around the world and how to write a short song or composition for the instruments they build.  They will use computer tools to record, edit and sequence sounds, analyze the characteristics of different sound colors, and notate their compositions.  No previous musical background required.'
    },
    'COMP 111': {
        title: 'Unix and Script Programming',
        description: 'Unix utilities and file structure; links and symbolic links; data processing and process control in the Unix shell; Shell programming; regular expressions; script programming in the Unix environment. Laboratory exercises are designed to give hands-on practice with software tools and to increase programmer productivity.'
    },
    'COMP 151': {
        title: 'Object-Oriented Programming',
        description: 'To learn the fundamental concepts and techniques behind object-oriented programming in C++. They include: abstract data types (classes, objects, and methods); creation, initialization, and destruction of objects; class hierarchies and inheritance; polymorphism and dynamic binding. In addition, generic programming using templates and algorithm abstraction will also be discussed.'
    },
    'COMP 151H': {
        title: 'Object-Oriented Programming (Honors Study Track)',
        description: 'Object-oriented programming in C++: abstract data types; object creation, initialization, and destruction; class hierarchies and inheritance; polymorphism and dynamic binding; templates and algorithm abstraction. More advanced object-oriented programming techniques based on a toolkit for large-scale component programming. Enrollment in the course requires approval of the course instructor.'
    },
    'COMP 170': {
        title: 'Discrete Mathematical Tools for Computer Science',
        description: 'Basic concepts in discrete mathematics needed for the study of computer science: enumeration techniques, basic number theory, logic and proofs, recursion and recurrences, probability theory and graph theory. The approach of this course is specifically computer science application oriented.'
    },
    'COMP 171': {
        title: 'Data Structures and Algorithms',
        description: 'Asymptotic notations.  Performance measurement.  Sorting and searching: algorithms and lower bound.  Abstract data types and classes.  Data structures: heaps, search trees, tries, and hashing.  Graphs: representation, depth-first-search, and breadth-first-search.'
    },
    'COMP 171H': {
        title: 'Data Structures and Algorithms (Honors Study Track)',
        description: 'Asymptotic notations.  Performance measurement.  Sorting and searching: algorithms and lower bound.  Abstract data types and classes.  Data structures: heaps, search trees, tries, and hashing.  Graphs: representation, depth-first-search, and breadth-first search.  This is a half-semester course.  Enrollment in the course requires approval of the course instructor.'
    },
    'COMP 180': {
        title: 'Computer Organization',
        description: 'Inner workings of modern digital computer systems and tradeoffs at the hardware-software interface.  Topics include: instructions set design, memory systems, input-output systems, interrupts and exceptions, pipelining, performance and cost analysis, assembly language programming, and a survey of advanced architectures.'
    },
    'COMP 190': {
        title: 'Directed Studies I (Honors Study Track)',
        description: 'Studies under the directed guidance of a faculty member on a computer science topic at 100-level.  A written report and/or an examination are required.  Enrollment in the course requires approval of the course instructor.  Courses may last for two semesters, depending on the topic and scope of study.'
    },
    'COMP 201': {
        title: 'Java Programming',
        description: 'Introduction to Java programming. Fundamentals include language syntax, object-oriented programming, inheritance, polymorphism, exception handling, multithreading. Standard libraries for input/output, graphics programming, built-in data structures. Application programming interface and foundation class library.'
    },
    'COMP 211': {
        title: 'Introduction to Software Engineering',
        description: 'Methods and tools for planning, designing, implementing, validating, and maintaining large software systems. Project work to build a software system as a team, using appropriate software engineering tools and techniques.'
    },
    'COMP 211H': {
        title: 'Introduction to Software Engineering (Honors Study Track)',
        description: 'Methods and tools for planning, designing, implementing, validating, and maintaining large software systems. A student-defined project allows students to build a software system as a team, using appropriate software engineering tools and techniques. Enrollment in the course requires approval of the course instructor.'
    },
    'COMP 221': {
        title: 'Fundamentals of Artificial Intelligence',
        description: 'Foundations underlying design of intelligent systems.  Relations between logical, statistical, cognitive, biological paradigms; basic techniques for heuristic search, theorem proving, knowledge representation, adaptation; applications in vision, language, planning, expert systems.'
    },
    'COMP 231': {
        title: 'Database Management Systems',
        description: 'Principles of database systems; conceptual modeling and data models; logical and physical database design; query languages and query processing; database services including concurrency, crash recovery, security and integrity. Hands-on DBMS experience.'
    },
    'COMP 251': {
        title: 'Principles of Programming Languages',
        description: 'Comparative studies of programming languages, programming language concepts and constructs. Non-imperative programming paradigms: object-oriented, functional, logic, concurrent programming. Basic concepts of program translation and interpretation. Storage allocation and run-time organization.'
    },
    'COMP 252': {
        title: 'Operating Systems',
        description: 'Principles, purpose and structure of operating systems; processes, threads, and multi-threaded programming; CPU scheduling; synchronization, mutual exclusion; memory management and virtual memory; device management; file systems, security and protection.'
    },
    'COMP 271': {
        title: 'Design and Analysis of Algorithms',
        description: 'Time and space complexity analysis of algorithms. Design paradigms: divide-and-conquer, greedy algorithms, dynamic programming. Graph algorithms: searching and backtracking, connectivity, biconnectivity, minimum spanning tree, shortest path. NP-completeness.'
    },
    'COMP 271H': {
        title: 'Design and Analysis of Algorithms (Honors Study Track)',
        description: 'Time and space complexity analysis of algorithms. Design paradigms: divide-and-conquer, greedy algorithms, dynamic programming. Graph algorithms: searching and backtracking, connectivity, biconnectivity, minimum spanning tree, shortest path. Fast Fourier Transform. Network flow. RSA and public key encryption. Randomized and amortized analysis. NP-completeness. Enrollment in the course requires approval of the course instructor.'
    },
    'COMP 272': {
        title: 'Theory of Computation',
        description: "Introduction to automata, formal languages, and computability.  Set theory and countability.  Finite automata and regular languages.  Push-down automata and context-free languages.  Turing machines.  Church's thesis.  Halting problem.  Uncomputability."
    },
    'COMP 290': {
        title: 'Directed Studies II (Honors Study Track)',
        description: 'Studies under the directed guidance of a faculty member on a computer science topic at 200-level.  A written report and/or an examination are required.  Enrollment in the course requires approval of the course instructor.  Courses may last for two semesters, depending on the topic and scope of study.'
    },
    'COMP 291': {
        title: 'Competitive Programming (Honors Study Track)',
        description: 'Intensive programming laboratory to equip students with creative problem solving and competitive programming skills. International programming competition-type problems will be used to motivate the study of algorithms, programming, and other topics in computer science. Enrollment in the course requires approval of the course instructor.'
    },
    'COMP 300': {
        title: 'Special Topics in Computer Science',
        description: 'Selected topics of current interest to the Department not covered by existing courses.  Offerings are announced each semester.'
    },
    'COMP 300E': {
        title: '',
        description: '',
    },
    'COMP 303': {
        title: 'Internet Computing',
        description: 'Technologies and standards for World Wide Web (WWW), user interfaces and Browsers, authoring tools, Internet protocols, Internet servers, database connectivity, Robots, Search engines, server-side programming, client-side programming, security and privacy, recent advances.'
    },
    'COMP 327': {
        title: 'Introduction to Pattern Recognition',
        description: 'Fundamentals of pattern recognition. Bayes decision theory. Parametric and non-parametric classifiers. Feature extraction and selection techniques. Pattern recognition applications. Project work to build a pattern recognition system.'
    },
    'COMP 328': {
        title: 'Machine Learning',
        description: 'Fundamentals of machine learning. Concept learning. Evaluating hypotheses. Supervised learning, unsupervised learning and reinforcement learning. Bayesian learning. Ensemble Methods.'
    },
    'COMP 332': {
        title: 'Principles of Database Design',
        description: 'Data modeling concepts; conceptual, logical and physical design; analyzing, evaluating and improving schemas; schema documentation and maintenance; functional analysis; design tools; schema mappings; database tuning; distributed database design.'
    },
    'COMP 334': {
        title: 'Distributed Database Systems',
        description: 'Distributed database system concepts: system architectures; database design and administration; query processing and optimization; transaction management; concurrency control; availability; recovery.  A course project using a commerical distributed DBMS is required.'
    },
    'COMP 336': {
        title: 'Search Engines for Web and Enterprise Data',
        description: 'Text retrieval models, vector space model, document ranking, performance evaluation; indexing, pattern matching, relevance feedback, clustering; web search engines, authority-based ranking; enterprise data management, content creation, meta data, taxonomy, ontology; semantic web, digital libraries and knowledge management applications.'
    },
    'COMP 337': {
        title: 'Introduction to Data Mining',
        description: 'This course will provide an introduction to concepts and techniques in the field of data mining. Material include an introduction to data preprocessing and the techniques used to explore the large quantities of data for the discovery of predictive models and knowledge.  The course will include data mining techniques such as nearest neighbor, decision trees, neural networks, Bayesian networks and Naïve Bayes, rule-based methods, association analysis and clustering, as well as social networks and data mining applications in business and finance applications.  We will also cover emerging data mining areas and applications. Students learn the material by attending lectures and implementing and applying different data analysis and data mining techniques to large datasets.',
    },
    'COMP 341': {
        title: 'Computer Graphics',
        description: 'Display technologies; scan conversion; clipping; affine transformations; homogeneous coordinates and projection; viewing transformations; hidden surface removal; reflectance and shading models; ray tracing; spline curves and surfaces; hierarchical modeling; texture mapping; color models.'
    },
    'COMP 342': {
        title: 'Introduction to Computer Music',
        description: 'An introductory course in the technology of computer music.  Music representation, music theory, musical acoustics, spectral analysis, sound synthesis techniques, sound modification techniques and effects.  No previous musical background required, but helpful.'
    },
    'COMP 343': {
        title: 'Multimedia Computing',
        description: 'Color theory; digital audio, image and video fundamentals, representation,and processing; digital multimedia applications and programming.'
    },
    'COMP 344': {
        title: 'Image Processing',
        description: 'Introduction to image processing. Topics include image processing and analysis in spatial and frequency domains, image restoration and compression, image segmentation and registration, morphological image processing, representation and description, related application areas and some other closely related topics. Some sophisticated image processing and analysis tools and state-of-the-art methods may also be introduced subject to the availability of time.'
    },
    'COMP 355': {
        title: 'Embedded Systems Software',
        description: 'Principles of software design and implementation for embedded systems; Timing, power, size and mobility constraints in embedded software design; basic hardware concepts; interrupts and interrupt handling; embedded operating system issues; real-time scheduling; real-time operating systems; embedded software development; integrated design environments; embedded networking; formal design methodologies, design examples.'
    },
    'COMP 361': {
        title: 'Computer Communication Networks I',
        description: 'Principles of computer network architectures and communication protocols; the OSI reference model; switching and multiplexing techniques; data link, network, transport and application layers; LAN and medium access protocols; network programming.'
    },
    'COMP 362': {
        title: 'Computer Communication Networks II',
        description: 'Multimedia requirements; bridges and their spanning tree protocol; advanced internet protocols (IPv6, Diffserv, IntServ, etc.); congestion control and QoS; multicast and broadcast algorithms; network performance and programming; introduction to network security.'
    },
    'COMP 364': {
        title: 'Computer and Communication Security',
        description: 'Cryptosystems, symmetric-key and public-key cryptography, cryptanalysis, authentication, message digests, digital signatures, and random number generation. Access controls and firewalls. Applications such as certificate authorities, electronic commerce, smartcards, and digital cash.'
    },
    'COMP 381': {
        title: 'Design and Analysis of Computer Architectures',
        description: 'Analysis, synthesis and evaluation of different computer architectures.  Emphasis on computer design with respect to price/performance and its relation to architectural choices such as pipelining, memory hierarchy, input/output, instruction set design, vector processing, and multiprocessing.'
    },
    'COMP 387': {
        title: 'Computer Engineering Final Year Thesis I',
        description: 'Only for honors students of the BEng Computer Engineering program. Students must take the whole course series comprising COMP/ELEC 387, 388 and 389 in sequence. They are expected to conduct research/independent work under the supervision of a faculty member of the Department of Computer Science and Engineering and/or Department of Electronic and Computer Engineering, summarize their work in an individual thesis and make a presentation at the end of the sequence. Work on COMP/ELEC 387 normally commences in the summer following the second year. May be graded PP.'
    },
    'COMP 388': {
        title: 'Computer Engineering Final Year Thesis II',
        description: 'Only for honors students of the BEng Computer Engineering program. Continuation of COMP 387. May be graded PP.'
    },
    'COMP 389': {
        title: 'Computer Engineering Final Year Thesis III',
        description: 'Only for honors students of the BEng Computer Engineering program. Continuation of COMP 388.'
    },
    'COMP 390': {
        title: 'Directed Studies III (Honors Study Track)',
        description: 'Studies under the directed guidance of a faculty member on a computer science topic at 300-level.  A written report and/or an examination are required.  Enrollment in the course requires approval of the course instructor.  Courses may last for two semesters, depending on the topic and scope of study.'
    },
    'COMP 394': {
        title: 'Computer Engineering Final Year Project I',
        description: 'Each Computer Engineering student is required to take COMP/ELEC 394, 395 and 396. The project is conducted under the supervision of a faculty member of the Department of Computer Science and Engineering and/or Department of Electronic and Computer Engineering. May be graded PP.'
    },
    'COMP 395': {
        title: 'Computer Engineering Final Year Project II',
        description: 'Continuation of COMP 394. May be graded PP.'
    },
    'COMP 396': {
        title: 'Computer Engineering Final Year Project III',
        description: 'Continuation of COMP 395.'
    },
    'COMP 397': {
        title: 'Final Year Project I',
        description: 'A project in an area of specialization in Computer Science under the guidance of a faculty member. Objectives are to integrate the classroom material from several courses, and to apply them to solve practical problems. May be graded PP.'
    },
    'COMP 397H': {
        title: 'Final Year Thesis I (Honors Study Track)',
        description: 'Students must take the whole course series comprising COMP 397H and COMP 398H in sequence. They are expected to conduct research work under the supervision of a faculty member, summarize their work in an individual thesis and make a presentation at the end of the sequence. Enrollment in the course requires approval of the course instructor. May be graded PP.'
    },
    'COMP 398': {
        title: 'Final Year Project II',
        description: 'Continuation of COMP 397.'
    },
    'COMP 398H': {
        title: 'Final Year Thesis II (Honors Study Track)',
        description: 'Continuation of COMP 397H.'
    },
    'COMP 510': {
        title: '',
        description: '',
    },
    'COMP 512': {
        title: 'Advanced Distributed Software Development',
        description: 'Introduction to important advanced concepts of software development in distributed environments.  Topics include models and analysis, object-oriented methodologies for enterprise applications, web technologies for building e-business systems.'
    },
    'COMP 522': {
        title: 'Machine Learning',
        description: 'Introduction to major learning paradigms and techniques, basic applied statistics and information theory, decision trees, neural networks, Bayesian classification, kernel methods, clustering, density estimation, feature selection and extraction, hidden Markov models, reinforcement learning, case-based learning, model selection and various applications.'
    },
    'COMP 524': {
        title: 'Computer Vision',
        description: 'Introduction to techniques for automatically describing visual data and tools for image analysis; perception of spatial organization; models of general purpose vision systems; computational and psychological models of perception.'
    },
    'COMP 526': {
        title: 'Natural Language Processing',
        description: 'Techniques for parsing, interpretation, context modeling, plan recognition, generation.  Emphasis on statistical approaches, neuropsychological and linguistic constraints, large text corpora.  Applications include machine translation, dialogue systems, cognitive modeling, knowledge acquisition.'
    },
    'COMP 530': {
        title: 'Database Architecture and Implementation',
        description: 'Introduction to the relational model and SQL.  System architectures and implementation techniques of database management systems: disk and memory management, access methods, implementation of relational operators, query processing and optimization, transaction management and recovery.  Hands on experience with building the components of a small DBMS.'
    },
    'COMP 537': {
        title: 'Knowledge Discovery in Databases',
        description: 'An introduction to knowledge discovery in databases.  Different discovery and learning techniques are presented and compared.  Automatic generation of query language expressions is discussed in depth.  Potential applications are shown.'
    },
    'COMP 538': {
        title: 'Introduction to Bayesian Networks',
        description: 'Bayesian networks and probabilistic modeling of complex domains; conditional independence and graph separation; variable elimination, clique tree propagation, and other inference algorithms; parameter learning; structure learning; latent structure models; recent developments.'
    },
    'COMP 561': {
        title: 'Computer Networks',
        description: 'Principles, design and implementation of computer communication networks; network architecture and protocols, OSI reference model and TCP/IP networking architecture; Internet applications and requirements; transport protocols, TCP and UDP; network layer protocols, IP, routing, multicasting and broadcasting; local area networks; data link and physical layer issues; TCP congestion control, quality of service, emerging trends in networking.'
    },
    'COMP 572': {
        title: 'Introduction to Combinatorial Optimization',
        description: 'An introduction to the basic tools of combinatorial optimization, including network flow and the max-flow min-cut theorem, linear programming, matching, spanning trees and matroids, dynamic programming, algorithms and data structures, graph algorithms.'
    },
    'COMP 573': {
        title: 'Computational Geometry',
        description: 'An introductory course in Computational Geometry.  Algorithms for manipulating geometric objects.  Topics include Convex Hulls, Voronoi Diagrams, Point Location, Triangulations, Randomized Algorithms, Point-Line Duality.'
    },
    'COMP 581': {
        title: 'Cryptography and Security',
        description: 'Classical encryption techniques, block and stream ciphers, public-key cryptography, authentication, nonrepudiation, key management, digital signatures, public key infrastructure, cryptographic protocol, secret sharing, electronic mail security, IP security, Web security, Firewalls, Intrusion detection.'
    },
    'COMP 610': {
        title: 'Topics in Software Engineering',
        description: 'Selected topics in software engineering of current interest to the Department and not covered by existing courses.'
    },
    'COMP 621': {
        title: 'Advanced Topics in Artificial Intelligence',
        description: 'Advanced topics in artificial intelligence including neural networks, natural language processing, logic programming, image understanding, robotics and others.'
    },
    'COMP 630': {
        title: 'Topics in Database Systems',
        description: 'Selected topics in database systems of current interest to the Department and not covered by existing courses.'
    },
    'COMP 641': {
        title: 'Topics in Graphics',
        description: 'Selected topics in graphics of current interest to the Department and not covered by existing courses.'
    },
    'COMP 651': {
        title: 'Topics in Computer Systems Analysis',
        description: 'Advanced topics in computer systems analysis; issues in the development and solution of system models; model parametrization, verification and validation; recent developments in techniques and tools for system evaluation.'
    },
    'COMP 660': {
        title: 'Topics in Computer and Communication Networks',
        description: 'Advanced topics in communication networks, including issues in high speed networking, ATM, multimedia communication, network interconnection, network management, and protocol verification and testing.'
    },
    'COMP 670': {
        title: 'Topics in Theoretical Computer Science',
        description: 'Selected topics in theoretical computer science not covered by existing courses, including, but not limited to, computational complexities and computability, graph algorithms and combinatorial optimization.'
    },
    'COMP 670J': {
        title: 'Approximation Algorithms',
        description: 'Most computer science researchers have given up on the possibility of finding techniques that always yield optimal solutions to NP-hard problems. This still leaves us with the task of finding \'good\' solutions to these problems. The theory of approximation algorithms is devoted to developing techniques that yield provably good (\'approximate\') solutions to these problems. In this course we will learn about the theory and practice of designing such algorithms.',
    },
    'COMP 670O': {
        title: 'Topics in Theory: Game Theoretic Applications in CS',
        description: 'A quick and dirty introduction to the basic concepts of modern game theory followed by a survey of recent work in computer science that uses game theory. The course will start with the instructor giving two or three introductory lessons on the basics of game theory. The remainder of the course will be students presenting papers.'
    },
    'COMP 670P': {
        title: 'Topics in Theory: Metric Embeddings and Algorithms',
        description: 'A quick and dirty introduction to the basic concepts of embeddings followed by a survey of recent work in computer science that uses embeddings. The course will start with the instructor giving two or three introductory lessons on the basics of  embeddings. The remainder of the course will be participants presenting papers.',
    },
    'COMP 680': {
        title: 'Topics in Computer Engineering',
        description: 'Selected topics in computer engineering of current interest to the Department and not covered by existing courses.'
    },
    'COMP 685': {
        title: 'Topics in Applications of Computer Science and Engineering',
        description: 'Selected topics in applications of computer science not covered by existing course. Credits earned by taking this course can only be used to satisfy the breath requirement of the research area of Software and Applications.'
    },
    'COMP 690': {
        title: 'Computer Science and Engineering Seminar I',
        description: 'A regular seminar presenting research problems currently under investigation. Students are expected to attend regularly. May be graded PP.'
    },
    'COMP 691': {
        title: 'Computer Science and Engineering Seminar II',
        description: 'Continuation of COMP 690. Graded P or F.'
    },
    'COMP 693': {
        title: 'Research Project',
        description: 'An independent research project carried out under the supervision of a faculty member.  This course is only available for exchange, visiting and visiting internship students.'
    },
    'COMP 696-697': {
        title: 'Independent Studies',
        description: 'An independent research project carried out under the supervision of a faculty member. (Only one independent studies course may be used to satisfy the course requirements for MPhil program. At most two independent studies courses may be used to satisfy the course requirement for PhD program.)'
    },
    'COMP 698': {
        title: 'MSc Research Project',
        description: 'An independent research project carried out under the supervision of a faculty member.  A project report is required and must be approved by two faculty members, one of whom is the supervisor.'
    },
    'COMP 699': {
        title: 'MPhil Thesis Research',
        description: "Master's thesis research supervised by a faculty member.  A successful defense of the thesis leads to Pass.  No course credit is assigned."
    },
    'COMP 799': {
        title: 'Doctoral Thesis Research',
        description: 'Original and independent doctoral thesis research supervised by a faculty member.  A successful defense of the thesis leads to Pass.  No course credit is assigned.'
    },
    'COMP 1001': {
        title: 'Exploring Multimedia and Internet Computing',
        description: 'This course is an introduction to computers and computing tools. It introduces the organization and basic working mechanism of a computer system, including the development of the trend of modern computer system. It covers the fundamentals of computer hardware design and software application development. The course emphasizes the application of the state-of-the-art software tools to solve problems and present solutions via a range of skills related to multimedia and internet computing tools such as internet, e-mail, WWW, webpage design, computer animation, spread sheet charts/figures, presentations with graphics and animations, etc. The course also covers business, accessibility, and relevant security issues in the use of computers and Internet.'
    },
    'COMP 1002': {
        title: 'Computer and Programming Fundamentals I',
        description: 'Introduction to computers and programming. Computer hardware and software. Problem solving. Program design. Procedural abstraction. Debugging and testing. Simple and structured data types. Recursive programming. Introduction to searching and sorting.'
    },
    'COMP 1021': {
        title: 'Introduction to Computer Science',
        description: 'This course introduces students to the world of Computer Science. Students will experience a range of fun and interesting areas from the world of computing, such as game programming, web programming, user interface design and computer graphics. These will be explored largely by programming in the Python language.'
    },
    'COMP 1022P': {
        title: 'Introduction to Computing with Java',
        description: 'This course is designed to equip students with the fundamental concepts of programming elements and data abstraction using Java. Students will learn how to write procedural programs using variables, arrays, control statements, loops, recursion, data abstraction and objects using an integrated development environment.'
    },
    'COMP 1022Q': {
        title: 'Introduction to Computing with Excel VBA',
        description: 'This course is designed to equip students with the fundamental concepts of programming using the VBA programming language, within the context of the Microsoft Excel program. Students will first learn how to use Excel to analyze and present data, and will then learn how to use VBA code to build powerful programs.'
    },
    'COMP 1029A': {
        title: 'Introduction to Mobile Application Development Using Android',
        description: 'This course provides a basic introduction to mobile application development using the Android platform. It is intended for students who have some prior programming experience, but wish to learn the basics of mobile application development. The course will introduce them to the Android SDK and development environment, Android application components: Activities and their lifecycle, UI design, Multimedia, and 2D graphics support in Android. Students explore these concepts through self-learning course materials and guided laboratory exercises. Graded P or F.'
    },
    'COMP 1029C': {
        title: 'C Programming Bridging Course',
        description: "This course introduces the C programming language. It is intended for students who already have some experience in computer programming but wish to learn how to apply those programming skills to the C language. The course covers basic programming topics, such as variables, control, loops, and functions, to more advanced topics. Students explore these by self-learning of course materials together with guided programming exercises. Students without the prerequisites but possess relevant programming knowledge may seek instructor's approval for enrolling in the course. Graded P or F."
    },
    'COMP 1029J': {
        title: 'Java Programming Bridging Course',
        description: "This course introduces the Java programming language. It is intended for students who already have some experience in computer programming but wish to learn how to apply those programming skills to the Java language. The course covers basic programming topics such as variables, control statements, loops, functions, and object-oriented programming concepts. Students explore these by self-learning of course materials together with guided programming exercises. Students without the prerequisites but possess relevant programming knowledge may seek instructor's approval for enrolling in the course. Graded P or F."
    },
    'COMP 1029P': {
        title: 'Python Programming Bridging Course',
        description: "This course introduces the Python programming language. It is intended for students who already have some experience in computer programming but wish to learn how to apply those programming skills to the Python language. The course covers basic programming topics, such as variables, functions and loops, to more advanced topics. Students explore these by self-learning of course materials together with guided programming exercises. Students without the prerequisites but possess relevant programming knowledge may seek instructor's approval for enrolling in the course. Graded P or F."
    },
    'COMP 1029V': {
        title: 'Excel VBA Programming Bridging Course',
        description: "This course introduces the VBA programming language, in the context of Microsoft Excel. It is intended for students who already have some experience in computer programming but wish to learn how to apply those programming skills to VBA, within Excel. The course covers basic programming topics, such as variables, functions and loops, to more advanced topics. Appropriate features of the Excel program are also covered. Students explore these by self-learning of course materials together with guided programming exercises. Students without the prerequisites but possess relevant programming knowledge may seek instructor's approval for enrolling in the course. Graded P or F."
    },
    'COMP 1900': {
        title: 'Academic and Professional Development I',
        description: 'A compulsory one-year course for students of the Department of Computer Science and Engineering under the three-year degree. This course is designed to provide academic advising to students and to develop their communication skills in interacting with technical and non-technical audiences. Graded P or F.'
    },
    'COMP 1941': {
        title: 'Great Ideas in Computing',
        description: 'Digital computing technology has brought many sweeping revolutions to our society. This course introduces some great and inspiring ideas in computing in the modern world, and discusses how people use computing tools to create useful solutions for challenging and important problems we are facing. Topics include artificial intelligence, data mining, biometrics, computational complexity, cryptography, efficient search, webpage ranking, network science, computer and society, and computational photography.'
    },
    'COMP 1942': {
        title: 'Exploring and Visualizing Data',
        description: 'This course teaches concepts and tools for exploring and visualizing data. There are a lot of real-life decision-making problems (e.g., business, logistics, economics, marketing, finance, resource management, forecasting and engineering) which can be formulated using some existing data analysis models. Existing computer science tools such as Microsoft Excel can help us to model and solve these problems easily, and to visualize the solutions.'
    },
    'COMP 1991': {
        title: 'Industrial Experience',
        description: "Full-time internship training for a period of at least six weeks in an organization or company recognized by the Department for providing qualified internship training relevant to the computer science and engineering profession. Cantonese or other working languages may be used in off-campus trainings and internships, in some situations. For students of the Department of Computer Science and Engineering in their second year of study or above only. Internship coordinator's approval is required for enrollment in the course. Graded P, PP or F."
    },
    'COMP 1999': {
        title: 'Industrial Training',
        description: 'A practical training course in a simulated industrial environment. For students of the Department of Computer Science and Engineering only. Graded P or F.'
    },
    'COMP 2011': {
        title: 'Programming with C++',
        description: 'This course covers programming and data structures using C++. In addition to basic programming concepts such as variables and control statements, students will learn about arrays, pointers, dynamic data allocation, linked lists, stacks, queues, binary trees, recursion, and the basics of object oriented programming.'
    },
    'COMP 2012': {
        title: 'Object-Oriented Programming and Data Structures',
        description: 'To learn the fundamental concepts and techniques behind object-oriented programming.  They include: abstract data types; creation, initialization, and destruction of objects; class hierarchies; polymorphism, inheritance and dynamic binding; generic programming using templates.  To learn the object-oriented view of data structures: linked lists, queues, stacks, trees, and algorithms such as searching, sorting, and hashing algorithms.'
    },
    'COMP 2012H': {
        title: 'Honors Object-Oriented Programming and Data Structures',
        description: 'This course is an accelerated and intensive course on concepts and techniques behind object-oriented programming (OOP) and data structures using an OOP language. It covers the major materials of COMP2011 and COMP2012, and its curriculum is designed for students with excellent programming background or substantial programming experience. Topics include: functions; pointers; abstract data types and their class implementation; static and dynamic construction and destruction of objects; data member and member functions; public interface and encapsulation; class hierarchies; polymorphism; inheritance and dynamic binding; standard template library; generic programming using templates; object-oriented view of data structures: linked lists, queues, stacks, trees, and their algorithms such as searching, sorting and hashing.'
    },
    'COMP 2021': {
        title: 'Unix and Script Programming',
        description: 'Unix utilities and file structure; links and symbolic links; data processing and process control in the Unix shell; Shell programming; regular expressions; script programming in the Unix environment.  Laboratory exercises are designed to give hands-on practice with software tools and to increase programmer productivity.'
    },
    'COMP 2521': {
        title: 'Mobile Application Development Projects',
        description: 'This course is intended to bring together students from different disciplines to focus on coming up with innovative mobile solutions to address domain-specific problems. This will be a student-led project-based course. Teams of students will focus on developing applications to address the needs of specific application domains. Learning additional technical knowledge will be demand-driven in self-learning mode. Students will be supported by technical advisors, which include a faculty member who is the main instructor, as well as instructional assistant(s) and student\nhelpers with technical knowledge.'
    },
    'COMP 2611': {
        title: 'Computer Organization',
        description: 'Inner workings of modern digital computer systems and tradeoffs at the hardware-software interface. Topics include: instructions set design, memory systems, input-output systems, interrupts and exceptions, pipelining, performance and cost analysis, assembly language programming, and a survey of advanced architectures.'
    },
    'COMP 2711': {
        title: 'Discrete Mathematical Tools for Computer Science',
        description: 'Basic concepts in discrete mathematics needed for the study of computer science: enumeration techniques, basic number theory, logic and proofs, recursion and recurrences, probability theory and graph theory. The approach of this course is specifically computer science application oriented.'
    },
    'COMP 2711H': {
        title: 'Honors Discrete Mathematical Tools for Computer Science',
        description: 'Discrete mathematics needed for the study of computer science: sets, functions; propositional logic, predicate logic, rules of inference, proof techniques; pigeonhole principle, basic and generalized permutations and combinations, binomial coefficients, inclusion-exclusion principle; probability theory, Bayes theorem, expectation, variance, random variables, hashing; cryptography and modular arithmetic, Euclid’s division theorem, multiplicative inverse, divisibility, RSA cryptosystem, Chinese remainder theorem; mathematical induction, strong induction and well-ordering property, recursion, recurrence relations; graph representation, isomorphism, connectivity, Euler paths, Hamilton paths, planarity, graph coloring. Gentle introduction to many discrete mathematical concepts that will appear later in more advanced computer science courses.'
    },
    'COMP 2900': {
        title: 'Academic and Professional Development II',
        description: 'Continuation of COMP 1900. A compulsory, one year course for students of the Department of Computer Science and Engineering under the three-year degree. Graded P or F.'
    },
    'COMP 3021': {
        title: 'Java Programming',
        description: 'Introduction to Java programming. Fundamentals include language syntax, object-oriented programming, inheritance, polymorphism, exception handling, multithreading. Standard libraries for input/output, graphics programming, built-in data structures. Programming for events, web, networking, generics.'
    },
    'COMP 3031': {
        title: 'Principles of Programming Languages',
        description: 'Comparative studies of programming languages, programming language concepts and constructs. Non-imperative programming paradigms: object-oriented, functional, logic, concurrent programming. Basic concepts of program translation and interpretation. Storage allocation and run-time organization.'
    },
    'COMP 3071': {
        title: 'Honors Competitive Programming',
        description: 'Intensive programming laboratory to equip students with creative problem solving and competitive programming skills. International programming competition-type problems will be used to motivate the study of algorithms, programming, and other topics in computer science. Enrollment in the course requires approval of the course instructor.'
    },
    'COMP 3111': {
        title: 'Software Engineering',
        description: 'Methods and tools for planning, designing, implementing, validating, and maintaining large software systems. Project work to build a software system as a team, using appropriate software engineering tools and techniques.'
    },
    'COMP 3111H': {
        title: 'Honors Software Engineering',
        description: 'General methodologies, techniques, and tools for planning, designing, implementing, validating, and maintaining large-scale software systems. Collaborative development environment, automatic static analysis, and testing techniques. Open source project development methodologies and techniques.'
    },
    'COMP 3211': {
        title: 'Fundamentals of Artificial Intelligence',
        description: 'Foundations underlying design of intelligent systems. Relations between logical, statistical, cognitive, biological paradigms; basic techniques for heuristic search, theorem proving, knowledge representation, adaptation; applications in vision, language, planning, expert systems.'
    },
    'COMP 3311': {
        title: 'Database Management Systems',
        description: 'Principles of database systems; conceptual modeling and data models; logical and physical database design; query languages and query processing; database services including concurrency, crash recovery, security and integrity. Hands-on DBMS experience.'
    },
    'COMP 3511': {
        title: 'Operating Systems',
        description: 'Principles, purpose and structure of operating systems; processes, threads, and multi-threaded programming; CPU scheduling; synchronization, mutual exclusion; memory management and virtual memory; device management; file systems, security and protection.'
    },
    'COMP 3632': {
        title: 'Principles of Cybersecurity',
        description: 'This course is an introduction to the principles of cybersecurity. Cybersecurity, also called computer security or IT security, refers to the study of techniques to protect computing systems from attacks that threaten data confidentiality, system integrity and availability. By modeling, analyzing, and evaluating the security of computer systems, students will learn to find weaknesses in software, hardware, networks, data storage systems, mobile applications, and the Internet, and identify current security practices and defenses to protect these systems.'
    },
    'COMP 3711': {
        title: 'Design and Analysis of Algorithms',
        description: 'Techniques for designing algorithms, proving their correctness, and analyzing their running times. Topics covered include: sorting, selection, heaps, balanced search trees, divide-and-conquer, greedy algorithms, dynamic programming, and graph algorithms.'
    },
    'COMP 3711H': {
        title: 'Honors Design and Analysis of Algorithms',
        description: 'Techniques for designing algorithms, proving their correctness, and analyzing their running times. Topics covered include: sorting, selection, heaps, balanced search trees, divide-and-conquer, greedy algorithms, dynamic programming, and graph algorithms. The class will also provide an introduction to advanced techniques such as amortized analysis and the design of randomized and approximation algorithms, as well as providing exposure to more advanced algorithmic solutions to optimization problems, e.g. linear programming and network flow.'
    },
    'COMP 3721': {
        title: 'Theory of Computation',
        description: 'This course is an introduction to the foundation of computation. Topics covered include set theory and  countability, formal languages, finite automata and regular languages, pushdown automata and context-free languages, Turing machines, undecidability, P and NP, NP completeness.'
    },
    'COMP 3900': {
        title: 'Academic and Professional Development III',
        description: 'Continuation of COMP 2900. A compulsory, one year course for students of the Department of Computer Science and Engineering under the three-year degree. Graded P or F.'
    },
    'COMP 4021': {
        title: 'Internet Computing',
        description: 'Technologies and standards for World Wide Web (WWW), user interfaces and Browsers, authoring tools, Internet protocols, Internet servers, database connectivity, Robots, Search engines, server-side programming, client-side programming, security and privacy, recent advances.'
    },
    'COMP 4111': {
        title: 'Software Engineering Practices',
        description: 'This course provides students with the exposure of effective real-world software engineering practices and the underlying concepts via working around a realistic modern software system and applying popular tools and practices in industry. Students will gain experience in collaborative software development as well as the skills required to succeed as software professional. Topics of the course cover advanced software engineering concepts, project setup, code management, testing, defect analysis, quality metrics, and issue management. For students of the Department of Computer Science and Engineering only.'
    },
    'COMP 4211': {
        title: 'Machine Learning',
        description: 'Fundamentals of machine learning. Concept learning. Evaluating hypotheses. Supervised learning, unsupervised learning and reinforcement learning. Bayesian learning. Ensemble Methods. Deep learning.'
    },
    'COMP 4221': {
        title: 'Introduction to Natural Language Processing',
        description: 'Human language technology for text and spoken language. Machine learning, syntactic parsing, semantic interpretation, and context-based approaches to machine translation, text mining, and web search.'
    },
    'COMP 4311': {
        title: 'Principles of Database Design',
        description: 'Data modeling concepts; conceptual, logical and physical design; analyzing, evaluating and improving schemas; schema documentation and maintenance; functional analysis; design tools; schema mappings; database tuning; distributed database design.'
    },
    'COMP 4321': {
        title: 'Search Engines for Web and Enterprise Data',
        description: 'Text retrieval models, vector space model, document ranking, performance evaluation; indexing, pattern matching, relevance feedback, clustering; web search engines, authority-based ranking; enterprise data management, content creation, meta data, taxonomy, ontology; semantic web, digital libraries and knowledge management applications.'
    },
    'COMP 4331': {
        title: 'Data Mining',
        description: 'This course will provide an introduction to concepts and techniques in the field of data mining. Materials include an introduction to data warehousing and OLAP, data preprocessing and the techniques used to explore the large quantities of data for the discovery of predictive models and knowledge. The course will include techniques such as nearest neighbor, decision tress, neural networks, Bayesian networks and Naive Bayes, rule-based methods, association analysis and clustering, as well as social networks and data mining applications in business and finance applications, and other emerging data mining subareas. Students learn the materials by attending lectures and implementing and applying different data analysis and mining techniques to large datasets throughout the semester.'
    },
    'COMP 4332': {
        title: 'Big Data Mining and Management',
        description: 'This course will expose students to new and practical issues of real world mining and managing big data. Data mining and management is to effectively support storage, retrieval, and extracting implicit, previously unknown, and potentially useful knowledge from data. This course will place emphasis on two parts. The first part is big data issues such as mining and managing on distributed data, sampling on big data and using some cloud computing techniques on big data. The second part is applications of the techniques learnt on areas such as business intelligence, science and engineering, which aims to uncover facts and patterns in large volumes of data for decision support. This course builds on basic knowledge gained in the introductory data-mining course, and explores how to more effectively mine and manage large volumes of real-world data and to tap into large quantities of data. Working on real world data sets, students will experience all steps of a data-mining and management project, beginning with problem definition and data selection, and continuing through data management, data exploration, data transformation, sampling, portioning, modeling, and assessment.'
    },
    'COMP 4411': {
        title: 'Computer Graphics',
        description: 'Display technologies; scan conversion; clipping; affine transformations; homogeneous coordinates and projection; viewing transformations; hidden surface removal; reflectance and shading models; ray tracing; spline curves and surfaces; hierarchical modeling; texture mapping; color models.'
    },
    'COMP 4421': {
        title: 'Image Processing',
        description: 'Introduction to image processing. Topics include image processing and analysis in spatial and frequency domains, image restoration and compression, image segmentation and registration, morphological image processing, representation and description, object recognition, related application areas and some other closely related topics. Some sophisticated image processing and analysis tools and state-of-the-art methods may also be introduced subject to the availability of time.'
    },
    'COMP 4431': {
        title: 'Multimedia Computing',
        description: 'Color theory; digital audio, image and video fundamentals, representation, and processing; digital multimedia applications and programming.'
    },
    'COMP 4441': {
        title: 'Computer Music',
        description: 'An introductory course in the technology of computer music. Music representation, music theory, musical acoustics, spectral analysis, sound synthesis techniques, sound modification techniques and effects. No previous musical background required, but helpful.'
    },
    'COMP 4451': {
        title: 'Game Programming',
        description: 'Computer game development touches on many facets of computer science, including computer graphics, artificial intelligence, algorithms, networking, human-computer interaction, music, and sound. This course will cover all of these aspects, with special emphasis on real-time graphics rendering. Students will get hands-on experience on how to design and implement real-world computer games, which will help improve their skills in programming, teamwork, management, and communication.'
    },
    'COMP 4511': {
        title: 'System and Kernel Programming in Linux',
        description: 'This course is designed to equip students, who have a particular interest in becoming practitioners, with substantial hands-on experience in solving concrete problems in a computer operating system, via programming, in a laboratory intensive course. Students will notably experiment with many topics in the areas of operating systems and network protocols, such as: boot loaders, shell, process management, system calls, process scheduler, file system, virtual memory, network protocols and packet filtering, system modules and device drivers. For students of the Department of Computer Science and Engineering only.'
    },
    'COMP 4521': {
        title: 'Mobile Application Development',
        description: 'Principles of application development for mobile and embedded devices. Mobile software development environments and software architectures. Features of typical mobile platforms: user-interface and user-experience design, multimedia, 2D and 3D graphics and data storage support, networking, location and mapping services. Design patterns and application frameworks. Mobile back-end support. Web applications. Students need to design and implement a full-fledged mobile application.'
    },
    'COMP 4611': {
        title: 'Design and Analysis of Computer Architectures',
        description: 'Analysis, synthesis and evaluation of different computer architectures. Emphasis on computer design with respect to price/performance and its relation to architectural choices such as pipelining, memory hierarchy, input/output, instruction set design, vector processing, and multiprocessing.'
    },
    'COMP 4621': {
        title: 'Computer Communication Networks I',
        description: 'Principles of computer network architectures and communication protocols; the OSI reference model; switching and multiplexing techniques; data link, network, transport and application layers; LAN and medium access protocols; network programming.'
    },
    'COMP 4622': {
        title: 'Computer Communication Networks II',
        description: 'Multimedia requirements; bridges and their spanning tree protocol; advanced internet protocols (IPv6, Diffserv, IntServ, etc.); congestion control and QoS; multicast and broadcast algorithms; network performance and programming; introduction to network security.'
    },
    'COMP 4631': {
        title: 'Computer and Communication Security',
        description: 'Cryptosystems, symmetric-key and public-key cryptography, cryptanalysis, authentication, message digests, digital signatures, and random number generation. Access controls and firewalls. Applications such as certificate authorities, electronic commerce, smartcards, and digital cash.'
    },
    'COMP 4632': {
        title: 'Practicing Cybersecurity: Attacks and Counter-measures',
        description: 'This course equips students with cybersecurity knowledge and current IT practices on security risk management. Through hands-on laboratory sessions, students will understand existing IT security issues, learn how to assess IT security risks, and conduct experiments on ethical hacking. They will practice system attack and defense strategies using security tools, so as to gain practical experience to become a cybersecurity professional. The course covers current security trends, industrial practices on IT security, design requirements for secure web and mobile applications, security assessment, risk analysis and risk management. Knowledge in web programming and database administration is not essential but a plus.'
    },
    'COMP 4641': {
        title: 'Social Information Network Analysis and Engineering',
        description: 'This course is an introduction to social information network analysis and engineering. Students will learn both mathematical and programming knowledge for analyzing the structures and dynamics of typical social information networks (e.g. Facebook, Twitter, and MSN). They will also learn how social metrics can be used to improve computer system design as people are the networks. It will cover topics such as small world phenomenon; contagion, tipping and influence in networks; models of network formation and evolution; the web graph and PageRank; social graphs and community detection; measuring centrality; greedy routing and navigations in networks; introduction to game theory and strategic\nbehavior; social engineering; and principles of computer system design. Students who do not have the prerequisites but with equivalent background may seek approval from the instructor for enrollment in the course.'
    },
    'COMP 4651': {
        title: 'Cloud Computing and Big Data Systems',
        description: 'Big data systems, including Cloud Computing and parallel data processing frameworks, emerge as enabling technologies in managing and mining the massive amount of data across hundreds or even thousands of commodity servers in datacenters. This course exposes students to both the theory and hands-on experience of this new technology. The course will cover the following topics. (1) Basic concepts of Cloud Computing and production Cloud services; (2) MapReduce - the de facto datacenter-scale programming abstraction - and its open source implementation of Hadoop. (3) Apache Spark - a new generation parallel processing framework - and its infrastructure, programming model, cluster deployment, tuning and debugging, as well as a number of specialized data processing systems built on top of Spark. By walking through a number of hands-on labs and assignments, students are expected to gain first-hand experience programming on real world clusters in production datacenters.'
    },
    'COMP 4900': {
        title: 'Academic and Professional Development',
        description: 'This course is for academic and professional development of students in the programs offered by the Department of Computer Science and Engineering. Activities may include seminars, workshops, advising and sharing sessions, interaction with faculty and teaching staff, and discussion with student peers or alumni. Graded P/PP/F.'
    },
    'COMP 4901': {
        title: 'Special Topics in Computer Science',
        description: 'Selected topics of current interest to the Department not covered by existing courses. Offerings are announced each semester. May be graded by letter, P/F, or DI/PA/F for different offerings.'
    },
    'COMP 4901U': {
        title: 'Computer Language Processing',
        description: 'Computer languages are now everywhere. Thus, basic computer language processing skills are essential to any self-respecting software engineer. From parsing ad-hoc configuration file formats, to validating complex specification languages, to generating efficient code solving data-intensive problems at scale, many important problems of today and tomorrow fall within this general domain. In this context, the usefulness of compiler theory and practice goes much beyond understanding the technology underlying your grandpa\'s old C compilers – our software-driven world is full of domain-specific languages that need correct and efficient implementations, and emergent areas like machine learning are more than ever in need of innovations from the fields of compilation and optimization. In this course, you will learn the essentials of computer language processing, including: parsing, analyzing, transforming, and compiling programs. You will learn to design and implement your own programming language and extend it with features of your choice in a small team project.',
    },
    'COMP 4911': {
        title: 'IT Entrepreneurship',
        description: 'Basic elements of starting a new business in information technology; exploiting an "unfair" advantage; preparing a business plan; arranging financial support; accounting and legal requirements; exit strategy. Case studies of successful and failed ventures in Hong Kong and elsewhere.'
    },
    'COMP 4971': {
        title: 'Independent Work',
        description: 'Independent studies or projects under the directed guidance of a faculty member on a computer science topic. A written report, presentation, and/or an examination are required. Enrollment in the course requires prior approval of the course instructor, and credits assigned depend on the workload. May be repeated for credits.'
    },
    'COMP 4981': {
        title: 'Final Year Project',
        description: 'Students are expected to complete a project in an area of specialization in Computer Science and Engineering under the guidance of a faculty member. Objectives are to integrate the classroom material from several courses, and to apply them to solve practical problems. Credit load will be spread over the year. For students in the BEng in Computer Science and BEng in Computer Engineering programs under the four-year degree only.'
    },
    'COMP 4981H': {
        title: 'Final Year Thesis',
        description: "Students are expected to conduct research under the supervision of a faculty member, summarize their work in an individual thesis and make a defense at the end. Credit load will be spread over the year. For students in the BEng in Computer Science and BEng in Computer Engineering programs under the four-year degree only. Instructor's approval is required for enrollment in the course."
    },
    'COMP 4982': {
        title: 'Final Year Project',
        description: 'Students are expected to complete a project in an area of specialization in Computer Science under the guidance of a faculty member. Objectives are to integrate the classroom material from several courses, and to apply them to solve practical problems. Credit load will be spread over the year.'
    },
    'COMP 4982H': {
        title: 'Final Year Thesis (Honors Study Track)',
        description: 'Students are expected to conduct research work under the supervision of a faculty member, summarize their work in an individual thesis and make a presentation at the end. Enrollment in the course requires approval of the course instructor. Credit load will be spread over the year.'
    },
    'COMP 4983': {
        title: 'Final Year Project I',
        description: 'A project in an area of specialization in Computer Science under the guidance of a faculty member. Objectives are to integrate the classroom material from several courses, and to apply them to solve practical problems. May be graded PP.'
    },
    'COMP 4983H': {
        title: 'Final Year Thesis I (Honors Study Track)',
        description: 'Students must take the whole course series comprising COMP 4983H and COMP 4984H in sequence.  They are expected to conduct research work under the supervision of a faculty member, summarize their work in an individual thesis and make a presentation at the end of the sequence.  Enrollment in the course requires approval of the course instructor.  May be graded PP.'
    },
    'COMP 4984': {
        title: 'Final Year Project II',
        description: 'Continuation of COMP 4983.'
    },
    'COMP 4984H': {
        title: 'Final Year Thesis II (Honors Study Track)',
        description: 'Continuation of COMP 4983H.'
    },
    'COMP 4988': {
        title: 'Computer Engineering Final Year Project',
        description: "Each student of the Computer Engineering program is required to complete a final year project before graduation. The student is expected to conduct a project on a topic related to Computer Engineering and/or its application. The project is guided and conducted under the supervision of faculty members from the Department of Computer Science and Engineering and/or the Department of Electronic and Computer Engineering. Instructor's approval is required for enrollment in the course. For CPEG students under the four-year degree only. May be graded PP."
    },
    'COMP 4989': {
        title: 'Computer Engineering Final Year Thesis',
        description: "Each student taking the Research Option of the Computer Engineering program is required to complete an individual thesis before graduation. The student is expected to conduct a research on a topic related to Computer Engineering and/or its application. The thesis is conducted under the supervision of faculty members from the Department of Computer Science and Engineering and/or the Department of Electronic and Computer Engineering. Instructor's approval is required for enrollment in the course. For CPEG students under the four-year degree only. May be graded PP."
    },
    'COMP 4991': {
        title: 'Computer Engineering Final Year Project',
        description: 'Each Computer Engineering student is required to complete a final year project before graduation. The project is conducted under the supervision of faculty members of the Department of Computer Science and Engineering and/or Department of Electronic and Computer Engineering. Credit load will be spread over 3 terms.'
    },
    'COMP 4992': {
        title: 'Computer Engineering Final Year Thesis',
        description: 'Only for honors students of the BEng Computer Engineering program. They are expected to conduct research/independent work under the supervision of faculty members of the Department of Computer Science and Engineering and/or Department of Electronic and Computer Engineering, summarize their work in an individual thesis and make a presentation at the end of the sequence. Credit load will be spread over 3 terms.'
    },
    'COMP 5111': {
        title: 'Fundamentals of Software Analysis',
        description: 'The goal of this course is to introduce how various analysis techniques can be used to manage the quality of a software application.  Students will acquire fundamental knowledge of program abstraction, features, verification, testing, refactoring, concurrency, reliability, aspect orientation, and fault analysis.  The course will also discuss how to carry out the empirical experimentation for program analysis.  Wherever applicable, concepts will be complemented by tools developed in academia and industry.  This enables students to understand the maturity and limitations of various analysis techniques.'
    },
    'COMP 5112': {
        title: 'Parallel Programming',
        description: 'Introduction to parallel computer architectures; principles of parallel algorithm design; shared-memory programming models; message passing programming models used for cluster computing; data-parallel programming models for GPUs; case studies of parallel algorithms, systems, and applications; hands-on experience with writing parallel programs for tasks of interest.'
    },
    'COMP 5211': {
        title: 'Advanced Artificial Intelligence',
        description: 'This advanced AI course will cover advanced concepts and techniques in AI.  The major topics will be: problem solving, knowledge and reasoning, planning, uncertain knowledge and reasoning, learning, and robotics.'
    },
    'COMP 5212': {
        title: 'Machine Learning',
        description: 'Introduction to major learning paradigms and techniques, basic applied statistics and information theory, decision trees, neural networks, Bayesian classification, kernel methods, clustering, density estimation, feature selection and extraction, hidden Markov models, reinforcement learning, case-based learning, model selection and various applications.'
    },
    'COMP 5213': {
        title: 'Introduction to Bayesian Networks',
        description: 'Bayesian networks and probabilistic modeling of complex domains; conditional independence and graph separation; variable elimination, clique tree propagation, and other inference algorithms; parameter learning; structure learning; latent structure models; recent developments.'
    },
    'COMP 5221': {
        title: 'Natural Language Processing',
        description: 'Techniques for parsing, interpretation, context modeling, plan recognition, generation.  Emphasis on statistical approaches, neuropsychological and linguistic constraints, large text corpora.  Applications include machine translation, dialogue systems, cognitive modeling, and knowledge acquisition.'
    },
    'COMP 5311': {
        title: 'Database Architecture and Implementation',
        description: 'Introduction to the relational model and SQL.  System architectures and implementation techniques of database management systems: disk and memory management, access methods, implementation of relational operators, query processing and optimization, transaction management and recovery.  Hands on experience with building the components of a small DBMS.'
    },
    'COMP 5312': {
        title: 'Introduction to Big Data',
        description: 'Big data foundation; big data infrastructure; cloud computing, parallel computing, and stream computing for big data; big data extraction and integration; big data management; big data mining; visual analytics of big data; big data platforms and tools; big data applications in business intelligence, smart city, and bioinformatics; hands-on experience with big data from real world.'
    },
    'COMP 5331': {
        title: 'Knowledge Discovery in Databases',
        description: 'An introduction to knowledge discovery in databases.  Different discovery and learning techniques are presented and compared.  Automatic generation of query language expressions is discussed in depth.  Potential applications are shown.'
    },
    'COMP 5411': {
        title: 'Advanced Computer Graphics',
        description: 'The first part of this course covers an introduction to mathematical tools and computational techniques for image synthesis and manipulation of 3D models.  The second part covers more advanced topics which may include digital geometry processing, image processing, visualization, GPU computing, numerical optimization methods.'
    },
    'COMP 5421': {
        title: 'Computer Vision',
        description: 'Introduction to techniques for automatically describing visual data and tools for image analysis; perception of spatial organization; models of general purpose vision systems; computational and psychological models of perception.'
    },
    'COMP 5531': {
        title: 'Green Computing',
        description: 'This course will exam "Green Computing" from a system perspective, meanwhile, students will study issues related to energy saving form multiple disciplines such as mechanical engineering, industrial ecology, and economics. We will explore energy efficient system designs ranging from datacenters to embed devices, such as sensor networks and RFID devices. We will perform Life Cycle Analysis on some of these systems, evaluating the carbon footprint of manufacturing, use, and disposal of each design.'
    },
    'COMP 5621': {
        title: 'Computer Networks',
        description: 'Principles, design and implementation of computer communication networks; network architecture and protocols, OSI reference model and TCP/IP networking architecture; Internet applications and requirements; transport protocols, TCP and UDP; network layer protocols, IP, routing, multicasting and broadcasting; local area networks; data link and physical layer issues; TCP congestion control, quality of service, emerging trends in networking.'
    },
    'COMP 5622': {
        title: 'Advanced Computer Communications and Networking',
        description: 'Advanced principles in computer and communication networking: Internet multicast, overlay and peer-to-peer networks; wireless and mobile computing, multimedia networking, network security, selected topics of current interests: wireless protocols, wireless security, sensor networks, cloud computing, data centers, software-defined networks, network implementation, etc.'
    },
    'COMP 5631': {
        title: 'Cryptography and Security',
        description: 'Classical encryption techniques, block and stream ciphers, public-key cryptography, authentication, nonrepudiation, key management, digital signatures, public key infrastructure, cryptographic protocol, secret sharing, electronic mail security, IP security, Web security, Firewalls, Intrusion detection.'
    },
    'COMP 5711': {
        title: 'Introduction to Advanced Algorithmic Techniques',
        description: 'This is an introductory graduate course in algorithmic techniques.  Topics include: advanced data structures; graph algorithms; amortization; approximation algorithms; on-line algorithms; randomized and probabilistic analysis.'
    },
    'COMP 5712': {
        title: 'Introduction to Combinatorial Optimization',
        description: 'An introduction to the basic tools of combinatorial optimization, including network flow and the max-flow min-cut theorem, linear programming, matching, spanning trees and matroids, dynamic programming, algorithms and data structures, graph algorithms.'
    },
    'COMP 5713': {
        title: 'Computational Geometry',
        description: 'An introductory course in Computational Geometry.  Algorithms for manipulating geometric objects.  Topics include Convex Hulls, Voronoi Diagrams, Point Location, Triangulations, Randomized Algorithms, Point-Line Duality.'
    },
    'COMP 6111': {
        title: 'Topics in Software Engineering',
        description: 'Selected topics in software engineering of current interest to the Department and not covered by existing courses.'
    },
    'COMP 6211': {
        title: 'Advanced Topics in Artificial Intelligence',
        description: 'Advanced topics in artificial intelligence including neural networks, natural language processing, logic programming, image understanding, robotics and others.'
    },
    'COMP 6311': {
        title: 'Topics in Database Systems',
        description: 'Selected topics in database systems of current interest to the Department and not covered by existing courses.'
    },
    'COMP 6411': {
        title: 'Topics in Graphics',
        description: 'Selected topics in graphics of current interest to the Department and not covered by existing courses.'
    },
    'COMP 6511': {
        title: 'Topics in Computer Systems Analysis',
        description: 'Advanced topics in computer systems analysis; issues in the development and solution of system models; model parametrization, verification and validation; recent developments in techniques and tools for system evaluation.'
    },
    'COMP 6611': {
        title: 'Topics in Computer and Communication Networks',
        description: 'Advanced topics in communication networks, including issues in high speed networking, ATM, multimedia communication, network interconnection, network management, and protocol verification and testing.'
    },
    'COMP 6612': {
        title: 'Topics in Computer Engineering',
        description: 'Selected topics in computer engineering of current interest to the Department and not covered by existing courses.'
    },
    'COMP 6613': {
        title: 'Topics in Applications of Computer Science and Engineering',
        description: 'Selected topics in applications of computer science not covered by existing course.  Credits earned by taking this course can only be used to satisfy the breath requirement of the research area of Software and Applications.'
    },
    'COMP 6711': {
        title: 'Topics in Theoretical Computer Science',
        description: 'Selected topics in theoretical computer science not covered by existing courses, including, but not limited to, computational complexities and computability, graph algorithms and combinatorial optimization.'
    },
    'COMP 6770': {
        title: 'Professional Development in Computer Science and Engineering',
        description: 'This one-credit course aims at providing research postgraduate students with basic training in teaching skills, research management, career development, and related professional skills. This course consists of a number of mini-workshops. Some department-specific workshops will be coordinated by Department of CSE. Graded PP, P or F.'
    },
    'COMP 6911': {
        title: 'Computer Science and Engineering Seminar I',
        description: 'A regular seminar presenting research problems currently under investigation. Students are expected to attend regularly. Graded P or F.'
    },
    'COMP 6912': {
        title: 'Computer Science and Engineering Seminar II',
        description: 'Continuation of COMP 6911. Graded P or F.'
    },
    'COMP 6921-6922': {
        title: 'Research Project',
        description: 'An independent research project carried out under the supervision of a faculty member. This course is only available for exchange, visiting and visiting internship students.'
    },
    'COMP 6931-6932': {
        title: 'Independent Studies',
        description: 'An independent research project carried out under the supervision of a faculty member. (Only one independent studies course may be used to satisfy the course requirements for any postgraduate program.)'
    },
    'COMP 6990': {
        title: 'MPhil Thesis Research',
        description: "Master's thesis research supervised by a faculty member.  A successful defense of the thesis leads to Pass.  No course credit is assigned."
    },
    'COMP 7990': {
        title: 'Doctoral Thesis Research',
        description: 'Original and independent doctoral thesis research supervised by a faculty member.  A successful defense of the thesis leads to Pass.  No course credit is assigned.'
    }
};
export default FETCHED_COURSES;
