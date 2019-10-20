<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8" isELIgnored="false"%>
<%
    pageContext.setAttribute("path", request.getContextPath());
%>
<!DOCTYPE HTML>
<html>
<head>
    <title>首页</title>
    <!-- 引入 Bootstrap -->
    <link href="https://cdn.bootcss.com/bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
<div class="container">
    <div class="row clearfix">
        <div class="col-md-12 column">
            <div class="page-header">
                <h1>
                    音乐商城
                </h1>
            </div>
        </div>
    </div>
</div>
<br><br>

<div class="col-md-2 col-md-offset-5">
    <div>
        <div class="row clearfix">
            <div class="col-md-6 column">
                <div class="page-header">
                    <h3>
                        请登录
                    </h3>
                </div>
            </div>
        </div>

    </div>

    <div>
        <form>
            <div class="form-group">
                <label>用户名</label>
                <input type="text" class="form-control" name="userName" placeholder="请输入用户名">
            </div>
            <div class="form-group">
                <label>密码</label>
                <input type="text" class="form-control" name="password" placeholder="请输入密码">
            </div>
            <div class="checkbox">
                <label>
                    <input type="checkbox"> 记住我（暂未设置）
                </label>
            </div>

            <button type="submit" class="btn btn-default" onclick="login()">登录</button>


        </form>

        <script type="text/javascript">
            function login() {
                var form = document.forms[0];
                form.action = "login";
                form.method = "post";
                form.submit();
            }
        </script>
        <br><br>
        <button onclick="location.href='${path}/Tourist/touristMusic'" class="btn btn-default">游客登录</button>

        <button onclick="location.href='${path}/toRegister'" class="btn btn-default">注册</button>
    </div>

</div>


</body>
</html>