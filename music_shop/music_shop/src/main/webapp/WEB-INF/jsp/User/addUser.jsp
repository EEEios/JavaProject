<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" isELIgnored="false"%>
<%
    pageContext.setAttribute("path", request.getContextPath());
%>
<html>
<head>
    <title>新增用户</title>
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
                    <small>新增用户</small>
                </h1>
            </div>
        </div>
    </div>

    <form action="" name="userForm">
        用户ID：<input type="text" name="userId"><br><br><br>
        用户账号：<input type="text" name="userName"><br><br><br>
        用户密码：<input type="text" name="password"><br><br><br>
        用户权限(0为普通用户，1为管理员)：<input type="text" name="power"><br><br><br>
        <input type="button" value="添加" onclick="addUser()">
    </form>

    <script type="text/javascript">
        function addUser() {
            var form = document.forms[0];
            form.action = "${path}/user/addUser";
            form.method = "post";
            form.submit();
        }
    </script>
</div>