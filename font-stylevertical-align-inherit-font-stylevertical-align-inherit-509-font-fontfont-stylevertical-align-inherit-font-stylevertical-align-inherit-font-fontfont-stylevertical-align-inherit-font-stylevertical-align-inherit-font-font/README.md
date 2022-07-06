<h2><a href="https://leetcode.com/problems/fibonacci-number/"><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">509 </font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">। </font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">ফিবোনাচি নম্বর</font></font></a></h2><h3>Easy</h3><hr><div><p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">ফিবোনাচি </font></font><b><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">সংখ্যাগুলি</font></font></b><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> সাধারণত </font></font><code>F(n)</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">একটি ক্রম গঠন করে, যাকে </font></font><b><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">ফিবোনাচি ক্রম</font></font></b><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> বলা হয় , যেমন প্রতিটি সংখ্যা হল এবং থেকে শুরু করে দুটি পূর্ববর্তী সংখ্যার </font></font><code>0</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">যোগফল </font></font><code>1</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">। </font><font style="vertical-align: inherit;">এটাই,</font></font></p>

<pre><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">F(0) = 0, F(1) = 1</font></font><font></font><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">
F(n) = F(n - 1) + F(n - 2), n &gt; 1 এর জন্য।</font></font><font></font>
</pre>

<p><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">দেওয়া হয়েছে </font></font><code>n</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">, হিসাব করুন </font></font><code>F(n)</code><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">।</font></font></p>

<p>&nbsp;</p>
<p><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">উদাহরণ 1:</font></font></strong></p>

<pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">ইনপুট:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> n = 2
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">আউটপুট:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 1
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">ব্যাখ্যা:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> F(2) = F(1) + F(0) = 1 + 0 = 1।
</font></font></pre>

<p><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">উদাহরণ 2:</font></font></strong></p>

<pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">ইনপুট:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> n = 3
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">আউটপুট:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 2
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">ব্যাখ্যা:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> F(3) = F(2) + F(1) = 1 + 1 = 2।
</font></font></pre>

<p><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">উদাহরণ 3:</font></font></strong></p>

<pre><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">ইনপুট:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> n = 4
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">আউটপুট:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> 3
 </font></font><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">ব্যাখ্যা:</font></font></strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;"> F(4) = F(3) + F(2) = 2 + 1 = 3।
</font></font></pre>

<p>&nbsp;</p>
<p><strong><font style="vertical-align: inherit;"><font style="vertical-align: inherit;">সীমাবদ্ধতা:</font></font></strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 30</code></li>
</ul>
</div>