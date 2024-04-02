
                    __      _ __             ___ ____ 
   ____ _____  ____/ /___  (_) /__  _____   <  // __ \
  / __ `/ __ \/ __  / __ \/ / / _ \/ ___/   / // / / /
 / /_/ / /_/ / /_/ / /_/ / / /  __/ /      / // /_/ / 
 \__, /\____/\__,_/ .___/_/_/\___/_/      /_(_)____/  
/____/           /_/                                  

 --by Evan Shaw
 

Starting with Project 2, I used the starter code that was given out. I based my typechecker, 3AC generator, and register allocator on that skeleton code. But it was quite terrible. First of all, the AST is way too split up to be very useful for parsing efficiently. It is what is known as a Concrete Syntax representation. Each feature of the parse language is reflected in the AST tree, which is very bad for eficient programming. 

I also made some programming design mistakes. I follwed the skeleton code pattern of recursive descent using different methods on the tree of structs. This might be ok if the AST was more cleaned up, but when I was building the typechecker and the systems added on to it, I did not think about this. The disparate layout of the AST tree is horrendous.

Due to poor program organization, I was spending a huge amount of time just debugging, and not actually writing code. All of my code had terrible side effects, and I was typing out similar code but on slight variations. I struggled to try and find a way to salvage the project, but alas, I could not come up with a better organizational method.

Right after Project 4, I knew things had to change. I had spend dozens of hours hammering out bugs, inching towards tiny features at a snail's pace. Hours upon hours of frustration, built inside me. Not finishing Project 4 was the final straw: I knew I had to rewrite the ENTIRE COMPILER!


And so I did... meet... "godpiler"! This compiler is completely new, programmed from the bottom up, with the finest Object Oriented C++ I could create the day after learning C++. The AST consists of dozens of object types. This arrangement is so much better than having a bunch of Structs that all look the same linked together in a cursed tree arrangement. The objects ensure that side-effects are rare to come accross. The biggest difference is that the methods associated with each object are tightly linked with the relevant data. This was not the case in my old compiler, where there was a single data type, and when writing methods, I would just have to guess at what data was actually there. I have implemented a few interfaces, like the Instruction interface, the StatementASTNode interface, and the ExpASTNode interface. This allows a more modular compiler. When I want to add more features, like new statements or instructions, I just have to implement an interface or two.

Another design aspect that is greatly improved is the instruction generation scheme. The tightly coupled objects only represent what is relevant to program execution and translation to assembly. On my old compiler, I would generate a sort of pseudo 3-address code, and then do another pass through the tree to translate it into rudimentary register assignments. This was a huge mistake.

On this compiler, I have fully implemented Liveness Analysis. If you try to compile a file, you may see the printout of the Liveness Table. Be sure to maximize your window! The liveness analysis is fully object oriented, while still providing easy access to the internals of the table. 

I have also fully implemented Interference Graph calculation. There is also a printout of the interference graph, but it is less understandable. This too is OOP, with the internal data being very easy to understand. I wish I had made a few more methods to help out however, because there are large nested for loops in the graph calculation code.

Finally, I have completely implemented the Chaitin-Briggs Graph Coloring Register Assignment Algorithm. I don't have quite as many heuristics as Briggs did in his famous paper, but I have added a few heuristics and shortcuts to determine whether to assign an Interference Node a caller-saved or callee-saved register. My code can determine whether or not the current method is a leaf node, and assigns register accordingly. 

If I had any more time, I would have loved to make a Spiller. I think spilling analysis would be rather fun to program, and I even came up with a few ideas while creating the rest of the compiler. Who knows? Maybe I'll get to it one day.

I started this rewrite on April 20th. I have put in ~87 hours (yes I am counting). You may ask, why would you redo your entire project just weeks before school ends? 87 Hours!?! That's crazy! Well that should tell you just how bad my old compiler was. In fact, I think the compiler rewrite actually saved me time in the end. And now I have my first project in C++, and I don't think it's half bad.

If you have any question for me about my project, feel free to ask! You can find me at shaw133@purdue.edu.

I had a lot of fun this year in CS352. I can't wait to see you all again next semester, when I have to take this class over again :)

Bye!










 
