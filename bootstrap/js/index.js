// $(document).ready(function () {
//     $('.navbar .container .nav-news-items .nav-news-items-ul').on('hover',function () {
//
//     })
// });
//



$(function () {
    var Shown=function (el) {
        var as = this.el.find('.a');
        as.on('click',this.showing);
    };
    Shown.prototype.showing=function () {
        $this=$(this);
        $this.addClass('showing');
    };
    var shown = new Shown($('.navbar .container .nav-news-items .nav-news-items-ul'));

});