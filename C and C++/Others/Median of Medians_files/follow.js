(function(root){
    // Follow click handler
    $(".btn-follow,.btn-unfollow").on("click", function(){
        var $this = $(this),
            followingId = $this.data('userid'),
            following = $this.hasClass('btn-unfollow');

        $this.addClass('disabled');
        $.ajax({
            type: following ? "DELETE" : "POST",
            url: "/followers" + (following ? "/" + followingId : ""),
            data: {'following_id': followingId},
            dataType: 'json'
        }).done(function(result){
            $this.removeClass('btn-info btn-danger btn-follow btn-unfollow disabled')
            if (following) {
                $this.addClass('btn-follow btn-info').html('Follow');
            } else {
                $this.addClass('btn-unfollow btn-danger').html('Unfollow');
            }
        }).fail(function(xhr, errorType, msg) {
            $this.removeClass('disabled');
            Utils.showAlert(Utils.error(xhr) || msg || 'Unknown Error');
        });
    });
})(this);
