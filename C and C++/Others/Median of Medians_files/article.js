(function($){
    // Initiate time ago plugin
    $('abbr.timeago').timeago();

    // Mark insightful click and callback
    $('#showArticleMedia').on('click', '.btn-insightful', function(){
        var $this = $(this),
            $count = $('.btn-insightful-count[data-article='+ $this.data('article') + ']');

        $this.addClass('disabled');
        $count.html((parseInt($count.html()) || 0) + 1);

        $.ajax({
            type: 'POST',
            url: '/' + ['articles', $this.data('article'), 'like'].join('/'),
            dataType: 'json'
        })
        .done(function(result) {
            $this.removeClass('disabled');
            if (result) {
                // display likes counter
                $count.html(result.likeCount);

                // Show marked as insightful
                $this.html("Marked as Insightful");
                $this.addClass('disabled');
            }
        })
        .fail(function(xhr, errorType, msg) {
            $this.removeClass('disabled');

            // decrement likes counter
            $count.html((parseInt($count.html()) || 1) - 1);
            Utils.showAlert(Utils.error(xhr) || msg || 'Unknown Error');
        });
    });

    // Update like count
    function updateArticleLike(result) {
        var article = result.article;
        if (article) {
            $('.btn-insightful-count[data-article='+ article.id + ']')
                .html(article.likeCount);
        }
    }

    //
    // Socket IO
    // ---------
    //
    var sc = App.socketContext;
    sc && sc.done(function(){
        var sck = App.socket,
            rt = App.realtime;
        if(sck) {
            rt.articlelikeChannel && sck.on(rt.articlelikeChannel, function (data) {
                updateArticleLike(JSON.parse(data));
            });
        }
    });
})(jQuery);
