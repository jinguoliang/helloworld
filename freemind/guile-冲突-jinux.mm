<map version="0.9.0">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1388762661485" ID="ID_1913795143" MODIFIED="1389009200548" TEXT="llllllllllllllllllll">
<node CREATED="1388762672157" ID="ID_1340934265" MODIFIED="1389009197360" POSITION="right" TEXT="feature">
<node CREATED="1388762687787" ID="ID_1970954646" MODIFIED="1388762855727" TEXT="extention:easy to wrap the function of C">
<node CREATED="1388762752865" ID="ID_1631918759" MODIFIED="1388762774402" TEXT="call each other with C"/>
</node>
<node CREATED="1388762776556" ID="ID_1852002703" MODIFIED="1388762861100" TEXT="modues: to decouple"/>
<node CREATED="1388762803446" ID="ID_417207072" MODIFIED="1388762825308" TEXT="open source"/>
<node CREATED="1388762818606" ID="ID_727904904" MODIFIED="1388978708252" TEXT="a REPL lib to "/>
</node>
<node CREATED="1389008601010" ID="ID_367474039" MODIFIED="1389009202240" POSITION="right" TEXT="Hello Scheme">
<node CREATED="1389008633792" FOLDED="true" ID="ID_1366544245" MODIFIED="1389014654097" TEXT="Data">
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
<node CREATED="1389008641664" FOLDED="true" ID="ID_1125411303" MODIFIED="1389014653353" TEXT="Procedure">
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
<node CREATED="1389008647560" FOLDED="true" ID="ID_1197414153" MODIFIED="1389014652234" TEXT="Expressions">
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
</html>
</richcontent>
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
</html>
</richcontent>
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
</html>
</richcontent>
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
</html>
</richcontent>
</node>
</node>
<node CREATED="1389008652327" ID="ID_1471699461" MODIFIED="1389058400922" TEXT="Closure">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      The concept of &quot;closure&quot; is the idea that a lambda expression
    </p>
    <p>
      &quot;captures&quot; the variable bindings that are in lexical scope at the point
    </p>
    <p>
      where the lambda expression occurs.&#160;&#160;The procedure created by the
    </p>
    <p>
      lambda expression can refer to and mutate the captured bindings, and the
    </p>
    <p>
      values of those bindings persist between procedure calls.
    </p>
  </body>
</html>
</richcontent>
<node CREATED="1389058414121" ID="ID_1517566382" MODIFIED="1389058437384" TEXT="About Environments">
<node CREATED="1389060486762" ID="ID_743254505" MODIFIED="1389060487846" TEXT=" A collection of associations between names and locations is called an &quot;environment&quot;."/>
<node CREATED="1389060530539" ID="ID_523614364" MODIFIED="1389060560950" TEXT="top level">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      &#160;The &quot;top level&quot; environment also includes
    </p>
    <p>
      name-location associations for all the procedures that are supplied by
    </p>
    <p>
      standard Scheme.
    </p>
  </body>
</html>
</richcontent>
<node CREATED="1389060623587" ID="ID_918908870" MODIFIED="1389060628410" TEXT=" create top level variables using the `define&apos; syntax"/>
</node>
</node>
<node CREATED="1389058448233" ID="ID_314888833" MODIFIED="1389058450863" TEXT="Local Variables">
<node CREATED="1389061394273" ID="ID_745288509" MODIFIED="1389061395273" TEXT="let">
<node CREATED="1389061396922" ID="ID_1255284169" MODIFIED="1389061397777" TEXT="The effect of the `let&apos; expression is to create a new environment"/>
</node>
</node>
<node CREATED="1389058455537" ID="ID_1841449448" MODIFIED="1389062712851" TEXT="Chaining">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      the local environment created by a `let'
    </p>
    <p>
      expression automatically has a reference to its containing environment
    </p>
    <p>
      Within the `let' body, the binding for `s' in the local environment
    </p>
    <p>
      is said to &quot;shadow&quot; the binding for `s' in the top level environment
    </p>
  </body>
</html>
</richcontent>
</node>
<node CREATED="1389058461473" ID="ID_1760927184" MODIFIED="1389058465677" TEXT="Lexical Scope">
<node CREATED="1389062966758" ID="ID_1676831388" MODIFIED="1389062969416" TEXT="an identifier at a particular place in a program always refers to      the same variable location -- where &quot;always&quot; means &quot;every time      that the containing expression is executed&quot;"/>
<node CREATED="1389062987708" ID="ID_870588294" MODIFIED="1389062990204" TEXT="the variable location to which it refers can be determined by      static examination of the source code context in which that      identifier appears, without having to consider the flow of      execution through the program as a whole"/>
</node>
<node CREATED="1389058471737" ID="ID_1958497529" MODIFIED="1389058473473" TEXT="Closure"/>
<node CREATED="1389058479801" ID="ID_777523720" MODIFIED="1389058481089" TEXT="Serial Number"/>
<node CREATED="1389058486130" ID="ID_828331896" MODIFIED="1389058487521" TEXT="Shared Variable"/>
<node CREATED="1389058493314" ID="ID_877042487" MODIFIED="1389058494463" TEXT="Callback Closure"/>
<node CREATED="1389058501146" ID="ID_1462323040" MODIFIED="1389058505377" TEXT="OO Closure"/>
</node>
<node CREATED="1389008659488" ID="ID_243952068" MODIFIED="1389008667498" TEXT="further reading"/>
</node>
</node>
</map>
