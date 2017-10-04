<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
 "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en"
 lang="en" dir="ltr">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <title>
    parse.rb    [C++ Reference]
  </title>

  <meta name="generator" content="DokuWiki Release 2009-12-25c &quot;Lemming&quot;" />
<meta name="robots" content="noindex,follow" />
<meta name="date" content="1969-12-31T16:00:00-0800" />
<meta name="keywords" content="parse.rb" />
<link rel="search" type="application/opensearchdescription+xml" href="http://www.cppreference.com/wiki/lib/exe/opensearch.php" title="C++ Reference" />
<link rel="start" href="index.html" />
<link rel="contents" href="http://www.cppreference.com/wiki/parse.rb?do=index" title="Index" />
<link rel="alternate" type="application/rss+xml" title="Recent Changes" href="http://www.cppreference.com/wiki/feed.php" />
<link rel="alternate" type="application/rss+xml" title="Current Namespace" href="http://www.cppreference.com/wiki/feed.php?mode=list&amp;ns=" />
<link rel="edit" title="Edit this page" href="http://www.cppreference.com/wiki/parse.rb?do=edit" />
<link rel="alternate" type="text/html" title="Plain HTML" href="http://www.cppreference.com/wiki/_export/xhtml/parse.rb" />
<link rel="alternate" type="text/plain" title="Wiki Markup" href="http://www.cppreference.com/wiki/_export/raw/parse.rb" />
<link rel="stylesheet" media="all" type="text/css" href="lib/exe/css.php@s=all&amp;t=custom1&amp;tseed=1265723194" />
<link rel="stylesheet" media="screen" type="text/css" href="lib/exe/css.php@t=custom1&amp;tseed=1265723194" />
<link rel="stylesheet" media="print" type="text/css" href="lib/exe/css.php@s=print&amp;t=custom1&amp;tseed=1265723194" />
<script type="text/javascript" charset="utf-8" ><!--//--><![CDATA[//><!--
var NS='';var JSINFO = {"id":"parse.rb","namespace":""};
//--><!]]></script>
<script type="text/javascript" charset="utf-8" src="lib/exe/js.php@tseed=1265723194" ></script>

  <link rel="shortcut icon" href="lib/tpl/custom1/images/favicon.png" />

  </head>

<body>
<div class="dokuwiki">
  
  <div class="stylehead">

    <div class="header">
      <div class="pagename">
        [[<a href="http://www.cppreference.com/wiki/parse.rb?do=backlink"  title="Backlinks">parse.rb</a>]]
      </div>
      <div class="logo">
        <a href="http://www.cppreference.com"  name="dokuwiki__top" id="dokuwiki__top" accesskey="h" title="[ALT+H]">C++ Reference</a>      </div>

      <div class="clearer"></div>
    </div>

    
    
        <div class="breadcrumbs">
      <span class="bchead">You are here: </span><a href="start"  title="start">C++ Reference</a> &raquo; <a href="parse.rb"  title="parse.rb" class="wikilink2" rel="nofollow">parse.rb</a>    </div>
    
  </div>

<div class="plugin_translation"><span>Translations of this page<sup><a href="localization" class="wikilink1" title="localization">?</a></sup>:</span> <ul>  <li><div class="li"><span class="curid"><a href="parse.rb" class="wikilink2" title="parse.rb" rel="nofollow">en</a></span></div></li>  <li><div class="li"><a href="http://www.cppreference.com/wiki/br-pt/parse.rb" class="wikilink2" title="br-pt:parse.rb" rel="nofollow">br-pt</a></div></li>  <li><div class="li"><a href="http://www.cppreference.com/wiki/cn/parse.rb" class="wikilink2" title="cn:parse.rb" rel="nofollow">cn</a></div></li>  <li><div class="li"><a href="http://www.cppreference.com/wiki/cz/parse.rb" class="wikilink2" title="cz:parse.rb" rel="nofollow">cz</a></div></li>  <li><div class="li"><a href="http://www.cppreference.com/wiki/de/parse.rb" class="wikilink2" title="de:parse.rb" rel="nofollow">de</a></div></li>  <li><div class="li"><a href="http://www.cppreference.com/wiki/es/parse.rb" class="wikilink2" title="es:parse.rb" rel="nofollow">es</a></div></li>  <li><div class="li"><a href="http://www.cppreference.com/wiki/fr/parse.rb" class="wikilink2" title="fr:parse.rb" rel="nofollow">fr</a></div></li>  <li><div class="li"><a href="http://www.cppreference.com/wiki/it/parse.rb" class="wikilink2" title="it:parse.rb" rel="nofollow">it</a></div></li>  <li><div class="li"><a href="http://www.cppreference.com/wiki/jp/parse.rb" class="wikilink2" title="jp:parse.rb" rel="nofollow">jp</a></div></li>  <li><div class="li"><a href="http://www.cppreference.com/wiki/nl/parse.rb" class="wikilink2" title="nl:parse.rb" rel="nofollow">nl</a></div></li>  <li><div class="li"><a href="http://www.cppreference.com/wiki/pl/parse.rb" class="wikilink2" title="pl:parse.rb" rel="nofollow">pl</a></div></li>  <li><div class="li"><a href="http://www.cppreference.com/wiki/ro/parse.rb" class="wikilink2" title="ro:parse.rb" rel="nofollow">ro</a></div></li>  <li><div class="li"><a href="http://www.cppreference.com/wiki/ru/parse.rb" class="wikilink2" title="ru:parse.rb" rel="nofollow">ru</a></div></li>  <li><div class="li"><a href="http://www.cppreference.com/wiki/sk/parse.rb" class="wikilink2" title="sk:parse.rb" rel="nofollow">sk</a></div></li>  <li><div class="li"><a href="http://www.cppreference.com/wiki/tr/parse.rb" class="wikilink2" title="tr:parse.rb" rel="nofollow">tr</a></div></li></ul></div>
  
  
  <div class="page">

    <script src="http://www.google-analytics.com/urchin.js" type="text/javascript">
</script>
<script type="text/javascript">
_uacct = "UA-2828341-1";
urchinTracker();
</script>
    <!-- wikipage start -->
    


<h1><a name="this_topic_does_not_exist_yet" id="this_topic_does_not_exist_yet">This topic does not exist yet</a></h1>
<div class="level1">

<p>

You&#039;ve followed a link to a topic that doesn&#039;t exist yet. If permissions allow, you may create it by using the <code>Create this page</code> button.
</p>

</div>

    <!-- wikipage stop -->
  </div>

  <div class="clearer">&nbsp;</div>

  
  <div class="stylefoot">

    <div class="meta">
      <div class="user">
              </div>
      <!--
      <div class="doc">
              </div>
      -->
    </div>

   
    <div class="bar" id="bar__bottom">
      <div class="bar-left" id="bar__bottomleft">
        <a href="http://www.cppreference.com/wiki/parse.rb?do=edit&amp;rev="  class="action create" accesskey="e" rel="nofollow">Create this page</a> &#149;
        <a href="http://www.cppreference.com/wiki/parse.rb?do=revisions"  class="action revisions" accesskey="o" rel="nofollow">Old revisions</a>      </div>
      <div class="bar-right" id="bar__bottomright">
         &#149;
         &#149;
         &#149;
        <a href="http://www.cppreference.com/wiki/parse.rb?do=login&amp;sectok=4dd8a6ce62d3bfe5d970f31afd4eaa92"  class="action login" rel="nofollow">Login</a> &#149;
        <a href="http://www.cppreference.com/wiki/parse.rb?do=index"  class="action index" accesskey="x" rel="nofollow">Index</a> &#149;
        <a href="http://www.cppreference.com/wiki/parse.rb?do=recent"  class="action recent" accesskey="r" rel="nofollow">Recent changes</a> &#149;
        <a  href="http://www.cppreference.com/wiki/feed.php" title="Recent changes RSS feed">RSS</a> &#149;
        <a href='http://creativecommons.org/licenses/by/3.0/us/' title='Creative Commons license'>cc</a> &#149;
        <form action="index.html" accept-charset="utf-8" class="search" id="dw__search"><div class="no"><input type="hidden" name="do" value="search" /><input type="text" id="qsearch__in" accesskey="f" name="id" class="edit" title="[ALT+F]" /><input type="submit" value="Search" class="button" title="Search" /><div id="qsearch__out" class="ajax_qsearch JSpopup"></div></div></form>&nbsp;
      </div>
      <div class="clearer"></div>
    </div>

  </div>

</div>

<div class="no"></div>
</body>
</html>
