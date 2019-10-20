<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" isELIgnored="false"%>
<%
    pageContext.setAttribute("path", request.getContextPath());
%>
<html>
<head>
    <title>新增音乐</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <!-- 引入 Bootstrap -->
    <link href="https://cdn.bootcss.com/bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
<div class="container">
    <div class="row clearfix">
        <div class="col-md-12 column">
            <div class="page-header">
                <h1>
                    音乐商城后台管理
                </h1>
            </div>
        </div>
    </div>

    <div class="row clearfix">
        <div class="col-md-12 column">
            <div class="page-header">
                <h1>
                    <small>新增音乐</small>
                </h1>
            </div>
        </div>
    </div>

    <form action="" name="userForm">
        音乐标题：<input type="text" name="musicName"><br><br><br>
        歌手：<input type="text" name="musicArtist"><br><br><br>
        所属专辑：<input type="text" name="musicAlbum"><br><br><br>
        专辑内序号：<input type="text" name="musicIdInAlbum"><br><br><br>
        发行日期：<input type="text" name="musicDate"><br><br><br>
        价格：<input type="text" name="musicPrice"><br><br><br>
        <input type="button" value="添加" onclick="addMusic()">
    </form>

    <script type="text/javascript">
        function addMusic() {
            var form = document.forms[0];
            form.action = "${path}/music/addMusic";
            form.method = "post";
            form.submit();
        }
    </script>
</div>