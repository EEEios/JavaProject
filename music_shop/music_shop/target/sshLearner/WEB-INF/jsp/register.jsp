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
                        用户注册
                    </h3>
                </div>
            </div>
        </div>

    </div>

    <div>
        <form action="" name="userForm">
            用户账号：<input type="text" name="userName"><br><br><br>
            用户密码：<input type="text" name="password"><br><br><br>
            <input type="button" value="添加" onclick="Register()">
        </form>

        <script type="text/javascript">
            function Register() {
                var form = document.forms[0];
                form.action = "${path}/register";
                form.method = "post";
                form.submit();
            }
        </script>
    </div>

</div>


</body>
</html>