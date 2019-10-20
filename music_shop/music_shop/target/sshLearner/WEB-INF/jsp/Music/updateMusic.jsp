<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" isELIgnored="false"%>
<%
    pageContext.setAttribute("path", request.getContextPath());
%>
<html>
<head>
    <title>修改音乐信息</title>
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
                    <small>修改音乐信息</small>
                </h1>
            </div>
        </div>
    </div>

    <form action="" name="userForm">
        <input type="hidden" name="musicId" value="${music.musicId}"/>
        音乐标题：<input type="text" name="musicName" value="${music.musicName}"/><br><br>
        歌手：<input type="text" name="musicArtist" value="${music.musicArtist}"/><br><br>
        所属专辑：<input type="text" name="musicAlbum" value="${music.musicAlbum }"/><br><br>
        专辑内序号：<input type="text" name="musicIdInAlbum" value="${music.musicIdInAlbum}"/><br><br>
        发行日期：<input type="text" name="musicDate" value="${music.musicDate}"/><br><br>
        价格：<input type="text" name="musicPrice" value="${music.musicPrice}"/><br><br>
        <input type="button" value="提交" onclick="updateMusic()"/>
    </form>

    <script type="text/javascript">
        function updateMusic() {
            var form = document.forms[0];
            form.action = "${path}/music/updateMusic";
            form.method = "post";
            form.submit();
        }
    </script>
</div>