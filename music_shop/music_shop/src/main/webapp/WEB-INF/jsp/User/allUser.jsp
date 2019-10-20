<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" isELIgnored="false"%>
<%
    pageContext.setAttribute("path", request.getContextPath());
%>
<html>
<head>
    <title>用户列表</title>
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
                    <small>用户列表 —— 显示所有用户</small>
                </h1>
            </div>
        </div>
    </div>

    <div class="row">
        <div class="col-md-1 column">
            <a class="btn btn-primary" href="${path}/user/toAddUser">新增</a>
        </div>
        <div class="col-md-4 column">
            <a class="btn btn-primary" href="${path}/user/allUser">查看全部用户</a>
        </div>


        <div class="col-md-6 column">
            <form action="${path}/user/searchUser" method="get" class="form-inline">
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
                    <th>用户编号</th>
                    <th>用户账号</th>
                    <th>用户密码</th>
                    <th>用户权限</th>
                </tr>
                </thead>
                <tbody>
                <c:forEach var="user" items="${requestScope.get('userlist')}" varStatus="status">
                    <tr>
                        <td>${user.userId}</td>
                        <td>${user.userName}</td>
                        <td>${user.password}</td>
                        <td>${user.power}</td>
                        <td>
                            <a href="${path}/user/toUpdateUser?id=${user.userId}">更改</a> |
                            <a href="${path}/user/del/${user.userId}">删除</a>
                        </td>
                    </tr>
                </c:forEach>
                </tbody>
            </table>
        </div>
    </div>
</div>
