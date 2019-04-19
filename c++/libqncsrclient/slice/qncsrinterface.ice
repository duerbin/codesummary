module csr
{
    interface ResultCallbackProxy
    {
        void sendStreamResult(string sessionid,string result);
    };

    interface StreamInterface
    {
        void initCallbackProxy(ResultCallbackProxy* proxy);
        void sendStreamData(string channelid,string strdata,int rate);
		int	 sendPackageData(string channelid,string packagedata);
    };
};
