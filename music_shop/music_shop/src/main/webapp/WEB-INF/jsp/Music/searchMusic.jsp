<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" isELIgnored="false"%>
<%
    pageContext.setAttribute("path", request.getContextPath());
%>
<html>
<head>
    <title>音乐列表</title>
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
                    <small>搜索结果</small>
                </h1>
            </div>
        </div>
    </div>

    <div class="row">
        <div class="col-md-1 column">
            <a class="btn btn-primary" href="${path}/music/toAddMusic">新增</a>
        </div>

        <div class="col-md-4 column">
            <a class="btn btn-primary" href="${path}/music/allMusic">查看全部音乐</a>
        </div>

        <div class="col-md-6 column">
            <form action="${path}/music/searchMusic" method="get" class="form-inline">
                <div class="form-group">
                    <label class="sr-only" for="exampleInputAmount">搜索</label>
                    <div class="input-group">
                        <input type="text" class="form-control" id="exampleInputAmount"
                               name="searchStr" placeholder="输入搜索内容">
                    </div>
                </div>
                <button type="submit" class="btn btn-primary">搜索</button>
            </form>
        </div>
    </div>

    <div class="row clearfix">
        <div class="col-md-12 column">
            <table class="table table-hover table-striped">
                <thead>
                <tr>
                    <th>音乐编号</th>
                    <th>音乐标题</th>
                    <th>歌手</th>
                    <th>所属专辑</th>
                    <th>专辑内序号</th>
                    <th>发行日期</th>
                    <th>价格</th>
                    <th>操作</th>
                </tr>
                </thead>
                <tbody>
                <c:forEach var="music" items="${requestScope.get('searchRes')}" varStatus="status">
                    <tr>
                        <td>${music.musicId}</td>
                        <td>${music.musicName}</td>
                        <td>${music.musicArtist}</td>
                        <td>${music.musicAlbum}</td>
                        <td>${music.musicIdInAlbum}</td>
                        <td>${music.musicDate}</td>
                        <td>${music.musicPrice}</td>
                        <td>
                            <a href="${path}/music/toUpdateMusic?id=${music.musicId}">更改</a> |
                            <a href="${path}/music/del/${music.musicId}">删除</a>
                        </td>
                    </tr>
                </c:forEach>
                </tbody>
            </table>
        </div>
    </div>
</div>
