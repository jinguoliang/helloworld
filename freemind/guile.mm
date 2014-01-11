<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1388762661485" ID="ID_1913795143" MODIFIED="1389099244049" TEXT="guile">
<node CREATED="1388762672157" ID="ID_1340934265" MODIFIED="1389009197360" POSITION="right" TEXT="feature">
<node CREATED="1388762687787" ID="ID_1970954646" MODIFIED="1388762855727" TEXT="extention:easy to wrap the function of C">
<node CREATED="1388762752865" ID="ID_1631918759" MODIFIED="1388762774402" TEXT="call each other with C"/>
</node>
<node CREATED="1388762776556" ID="ID_1852002703" MODIFIED="1388762861100" TEXT="modues: to decouple"/>
<node CREATED="1388762803446" ID="ID_417207072" MODIFIED="1388762825308" TEXT="open source"/>
<node CREATED="1388762818606" ID="ID_727904904" MODIFIED="1388978708252" TEXT="a REPL lib to "/>
</node>
<node CREATED="1389008601010" ID="ID_367474039" MODIFIED="1389009202240" POSITION="right" TEXT="Hello Scheme">
<node CREATED="1389008633792" ID="ID_1366544245" MODIFIED="1389143164214" TEXT="Data">
<node CREATED="1389008682345" ID="ID_1127294926" MODIFIED="1389008710451" TEXT="lathent type">
<node CREATED="1389009655514" ID="ID_745223866" MODIFIED="1389009656946" TEXT="Dynamic typing, also called latent typing,"/>
</node>
<node CREATED="1389009225327" ID="ID_188249208" MODIFIED="1389009231392" TEXT="values and variable">
<node CREATED="1389009771028" ID="ID_887001146" MODIFIED="1389009772494" TEXT=" A variable, on the other hand, has no fixed type"/>
<node CREATED="1389009787653" ID="ID_1906941856" MODIFIED="1389009788748" TEXT="all values in Scheme - carry their type with them."/>
</node>
<node CREATED="1389009234247" ID="ID_498682204" MODIFIED="1389009246604" TEXT="definition">
<node CREATED="1389009816990" ID="ID_1334383993" MODIFIED="1389009818181" TEXT="(define VARIABLE-NAME VALUE)"/>
<node CREATED="1389009833294" ID="ID_884362155" MODIFIED="1389009835023" TEXT="(set! VARIABLE-NAME NEW-VALUE)"/>
</node>
</node>
<node CREATED="1389008641664" ID="ID_1125411303" MODIFIED="1389143160870" TEXT="Procedure">
<node CREATED="1389009944601" ID="ID_1100690996" MODIFIED="1389009945609" TEXT="Procedures as Values"/>
<node CREATED="1389009958368" ID="ID_1673985974" MODIFIED="1389009959283" TEXT="Simple Invocation">
<node CREATED="1389010132237" ID="ID_723353524" MODIFIED="1389010133949" TEXT="(PROCEDURE [ARG1 [ARG2 ...]])"/>
</node>
<node CREATED="1389009967353" ID="ID_526462251" MODIFIED="1389009968801" TEXT="Creating a Procedure">
<node CREATED="1389010212975" ID="ID_120328276" MODIFIED="1389010353592" TEXT="(define fun (lambda (x) exp....))"/>
</node>
<node CREATED="1389009974593" ID="ID_1697724975" MODIFIED="1389009975321" TEXT="Lambda Alternatives">
<node CREATED="1389010358803" ID="ID_85513104" MODIFIED="1389010375971" TEXT="(define (fun x1 x2) exp....)"/>
</node>
</node>
<node CREATED="1389008647560" FOLDED="true" ID="ID_1197414153" MODIFIED="1389143321302" TEXT="Expressions">
<font ITALIC="true" NAME="SansSerif" SIZE="12"/>
<node CREATED="1389010501958" ID="ID_1693869646" MODIFIED="1389010514613" TEXT="Evaluating">
<node CREATED="1389010773605" ID="ID_470629892" MODIFIED="1389010776885" TEXT="Evaluation has two kinds of result:">
<node CREATED="1389010786925" ID="ID_834237843" MODIFIED="1389010788493" TEXT="the &quot;value&quot; of the evaluated expression"/>
<node CREATED="1389010842446" ID="ID_734898711" MODIFIED="1389010843270" TEXT="the &quot;side effects&quot; of the evaluation"/>
</node>
<node CREATED="1389011179537" ID="ID_1467444967" MODIFIED="1389011181156" TEXT="Eval Literal">
<node CREATED="1389011260042" ID="ID_1958543987" MODIFIED="1389011390460" TEXT="String:&quot;abc&quot;"/>
<node CREATED="1389011270691" ID="ID_1652577729" MODIFIED="1389011354375" TEXT="complex number:5+3i  "/>
<node CREATED="1389011276380" ID="ID_515628367" MODIFIED="1389011378951" TEXT="vector:#(2 3 4)"/>
</node>
<node CREATED="1389011187145" ID="ID_1872204956" MODIFIED="1389012505422" TEXT="Eval Variable"/>
<node CREATED="1389011195698" ID="ID_949789080" MODIFIED="1389012518472" TEXT="Eval Procedure">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      For a procedure defined in Scheme, &quot;calling the procedure with the
    </p>
    <p>
      list of values as its parameters&quot; means binding the values to the
    </p>
    <p>
      procedure's formal parameters and then evaluating the sequence of
    </p>
    <p>
      expressions that make up the body of the procedure definition.
    </p>
  </body>
</html></richcontent>
<node CREATED="1389012418205" ID="ID_687499741" MODIFIED="1389012419997" TEXT="The value of the procedure invocation expression is the value of the last evaluated expression in the procedure body."/>
</node>
<node CREATED="1389011207514" ID="ID_1769525704" MODIFIED="1389012730290" TEXT="Eval Special">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      When a procedure invocation expression is evaluated, the procedure and
    </p>
    <p>
      _all_ the argument expressions must be evaluated before the procedure
    </p>
    <p>
      can be invoked.
    </p>
    <p>
      
    </p>
    <p>
      Special syntactic expressions are special because they
    </p>
    <p>
      are able to manipulate their arguments in an unevaluated form, and can
    </p>
    <p>
      choose whether to evaluate any or all of the argument expressions.
    </p>
  </body>
</html></richcontent>
<node CREATED="1389012733373" ID="ID_817529537" MODIFIED="1389012755455" TEXT="the difference with procedure">
<node CREATED="1389012757263" ID="ID_98352033" MODIFIED="1389012800606" TEXT="eval partial "/>
</node>
</node>
</node>
<node CREATED="1389010523990" ID="ID_685956883" MODIFIED="1389014627351" TEXT="Tail Calls">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Scheme is &quot;properly tail recursive&quot;, meaning that tail calls or
    </p>
    <p>
      recursions from certain contexts do not consume stack space or other
    </p>
    <p>
      resources and can therefore be used on arbitrarily large data or for an
    </p>
    <p>
      arbitrarily long calculation.
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1389010530687" ID="ID_729735025" MODIFIED="1389010531615" TEXT="The REPL"/>
<node CREATED="1389010537839" ID="ID_410659886" MODIFIED="1389014649718" TEXT="Syntax Summary">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      `lambda' (*note Lambda::) is used to construct procedure objects.
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;`define' (*note Top Level::) is used to create a new variable and
    </p>
    <p>
      set its initial value.
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;`set!' (*note Top Level::) is used to modify an existing variable's
    </p>
    <p>
      value.
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;`let', `let*' and `letrec' (*note Local Bindings::) create an inner
    </p>
    <p>
      lexical environment for the evaluation of a sequence of expressions, in
    </p>
    <p>
      which a specified set of local variables is bound to the values of a
    </p>
    <p>
      corresponding set of expressions.&#160;&#160;For an introduction to environments,
    </p>
    <p>
      &#160;&#160;&#160;`begin' (*note begin::) executes a sequence of expressions in order
    </p>
    <p>
      and returns the value of the last expression.&#160;&#160;Note that this is not the
    </p>
    <p>
      same as a procedure which returns its last argument, because the
    </p>
    <p>
      evaluation of a procedure invocation expression does not guarantee to
    </p>
    <p>
      evaluate the arguments in order.
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;`if' and `cond' (*note Conditionals::) provide conditional
    </p>
    <p>
      evaluation of argument expressions depending on whether one or more
    </p>
    <p>
      conditions evaluate to &quot;true&quot; or &quot;false&quot;.
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;`case' (*note Conditionals::) provides conditional evaluation of
    </p>
    <p>
      argument expressions depending on whether a variable has one of a
    </p>
    <p>
      specified group of values.
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;`and' (*note and or::) executes a sequence of expressions in order
    </p>
    <p>
      until either there are no expressions left, or one of them evaluates to
    </p>
    <p>
      &quot;false&quot;.
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;`or' (*note and or::) executes a sequence of expressions in order
    </p>
    <p>
      until either there are no expressions left, or one of them evaluates to
    </p>
    <p>
      &quot;true&quot;.
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1389008652327" FOLDED="true" ID="ID_1471699461" MODIFIED="1389360050433" TEXT="Closure">
<node CREATED="1389143348553" ID="ID_1380897017" MODIFIED="1389143365762" TEXT="About Environment">
<node CREATED="1389143489954" ID="ID_1898877682" MODIFIED="1389143491817" TEXT="A collection of associations between names and locations is called an &quot;environment&quot;."/>
<node CREATED="1389143513154" ID="ID_1481998841" MODIFIED="1389143513809" TEXT="you create a top level variable in a program using `define&apos;, the name-location association for that variable is added to the &quot;top level&quot; environment"/>
<node CREATED="1389143538651" ID="ID_663503235" MODIFIED="1389143544082" TEXT="define ">
<node CREATED="1389143558267" ID="ID_1673732529" MODIFIED="1389143558947" TEXT="the operation of the `define&apos; syntax">
<node CREATED="1389143564091" ID="ID_1266800025" MODIFIED="1389143570258" TEXT=" creates a new location"/>
<node CREATED="1389143587500" ID="ID_1694640384" MODIFIED="1389143590946" TEXT="establishes an association between that location and the name      specified as the first argument of the `define&apos; expression"/>
<node CREATED="1389143599628" ID="ID_697881297" MODIFIED="1389143602475" TEXT="stores in that location the value obtained by evaluating the second      argument of the `define&apos; expression"/>
</node>
</node>
</node>
<node CREATED="1389143666693" ID="ID_1494995622" MODIFIED="1389143692540" TEXT="Local Variables">
<node CREATED="1389143810056" ID="ID_177136703" MODIFIED="1389143812510" TEXT="The effect of the `let&apos; expression is to create a new environment"/>
</node>
<node CREATED="1389143699732" ID="ID_1772707791" MODIFIED="1389143703469" TEXT="Chaining">
<node CREATED="1389143988604" ID="ID_1988824603" MODIFIED="1389143990993" TEXT="the local environment created by a `let&apos; expression automatically has a reference to its containing environment"/>
</node>
<node CREATED="1389143713558" ID="ID_187719456" MODIFIED="1389143716273" TEXT="Lexical Scope">
<node CREATED="1389146404173" ID="ID_185778895" MODIFIED="1389146406672" TEXT="an identifier at a particular place in a program always refers to      the same variable location"/>
<node CREATED="1389146420336" ID="ID_1966544098" MODIFIED="1389146422072" TEXT="the variable location to which it refers can be determined by      static examination of the source code context in which that      identifier appears, without having to consider the flow of      execution through the program as a whole"/>
<node CREATED="1389146664637" ID="ID_1556462525" MODIFIED="1389146668189" TEXT="elisp">
<node CREATED="1389146672329" ID="ID_454938144" MODIFIED="1389146679195" TEXT="non-lexical scope">
<node CREATED="1389146698827" ID="ID_1869312349" MODIFIED="1389146701355" TEXT="is a &quot;dynamically scoped&quot; language">
<node CREATED="1389146738413" ID="ID_1511350995" MODIFIED="1389146740741" TEXT="all variable bindings go onto a single stack"/>
</node>
</node>
</node>
</node>
<node CREATED="1389143758166" ID="ID_990940524" MODIFIED="1389143760950" TEXT="Closure">
<node CREATED="1389146810400" ID="ID_1336932765" MODIFIED="1389146821152" TEXT="When the Scheme interpreter evaluates a `lambda&apos; expression, to      create a procedure object, it stores the current environment as      part of the procedure definition"/>
<node CREATED="1389146823440" ID="ID_1466105822" MODIFIED="1389146830880" TEXT="Then, whenever that procedure is called, the interpreter      reinstates the environment that is stored in the procedure      definition and evaluates the procedure body within the context of      that environment"/>
</node>
<node CREATED="1389143766629" ID="ID_568249730" MODIFIED="1389146902826" TEXT="Serial Number">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      (define (make-serial-number-generator)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;(let ((current-serial-number 0))
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(lambda ()
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(set! current-serial-number (+ current-serial-number 1))
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;current-serial-number)))
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;(define entry-sn-generator (make-serial-number-generator))
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;(entry-sn-generator)
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1389143774855" ID="ID_529262648" MODIFIED="1389146894345" TEXT="Shared Variable">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#160;&#160;&#160;&#160;&#160;(define get-balance #f)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;(define deposit #f)
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;(let ((balance 0))
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;(set! get-balance
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(lambda ()
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;balance))
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;(set! deposit
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(lambda (amount)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(set! balance (+ balance amount))
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;balance)))
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;(define (withdraw amount)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;(deposit (- amount)))
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1389143782215" ID="ID_219713995" MODIFIED="1389146942444" TEXT="Callback Closure">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#160;&#160;&#160;&#160;&#160;;; In the library:
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;(define (register-callback event-type handler-proc)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;...)
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;;; In the application:
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;(define (make-handler event-type user-data)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;(lambda ()
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;...
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&lt;code referencing event-type and user-data&gt;
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;...))
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;(register-callback event-type
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(make-handler event-type ...))
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1389143789695" ID="ID_1280020481" MODIFIED="1389146954063" TEXT="OO Closure">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#160;&#160;&#160;&#160;&#160;(define (make-account)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;(let ((balance 0))
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(define (get-balance)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;balance)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(define (deposit amount)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(set! balance (+ balance amount))
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;balance)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(define (withdraw amount)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(deposit (- amount)))
    </p>
    <p>
      
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(lambda args
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(apply
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(case (car args)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;((get-balance) get-balance)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;((deposit) deposit)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;((withdraw) withdraw)
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(else (error &quot;Invalid method!&quot;)))
    </p>
    <p>
      &#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;(cdr args)))))
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1389008659488" ID="ID_243952068" MODIFIED="1389008667498" TEXT="further reading"/>
</node>
</node>
</map>
